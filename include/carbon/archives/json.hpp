#pragma once
#include "deps/rapidjson/document.h"
#include "../detail/proxy_ref.hpp"
#include "../detail/serialization_tag.hpp"
#include "deps/rapidjson/prettywriter.h"
#include "deps/rapidjson/istreamwrapper.h"
#include <stack>

namespace carbon { namespace archive {

    class json_input {
        rapidjson::Document                         _document;
        std::stack<rapidjson::Document::ValueType*> _members;
        rapidjson::Document::ValueType*             _cur_member;

    public:
        json_input(std::istream& stream) : _cur_member(&_document)
        {
            rapidjson::IStreamWrapper stream_wrap(stream);
            _document.ParseStream(stream_wrap);
            _members.push(&_document);
        }

        template<class T, class Tag>
        void begin_object()
        {
           /* typename Tag::storage name;
            Tag::copy_to_storage(name);
            _cur_member =
                &_cur_member
                     ->AddMember({ name, Tag::size }, { rapidjson::kObjectType })
                     .value;
        */}

           template<class T, class Tag>
           void copy(T& value)
           {
               /*value = _iters.top()->value.Get<T>();
               ++_iters.top();*/
           }

           template<class T, class Tag>
           void end_object()
           {
               /*_members.pop();
               _cur_member = _members.top();*/
           }
    };

    class json_output {
        std::ostream&                               _stream;
        rapidjson::Document                         _document;
        std::stack<rapidjson::Document::ValueType*> _iters;
        rapidjson::Document::ValueType*             _cur_member;

    public:
        json_output(std::ostream& stream)
            : _stream(stream)
            , _document(rapidjson::kObjectType)
            , _cur_member(&_document)
        {}

        ~json_output()
        {
            rapidjson::StringBuffer                          buffer;
            rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
            _document.Accept(writer);
            _stream.write(buffer.GetString(), buffer.GetSize());
        }

        template<class T, class Tag>
        void begin_object()
        {
            typename Tag::storage name;
            Tag::copy_to_storage(name);
            auto old_member = _cur_member;
            _cur_member     = &_cur_member->AddMember(
                rapidjson::GenericStringRef<char>(Tag::str),
                rapidjson::Document::ValueType(rapidjson::kObjectType),
                _document.GetAllocator());
            _iters.push(old_member);
        }

        template<class T, class Tag>
        void copy(T& value)
        {
            _cur_member->AddMember(rapidjson::GenericStringRef<char>(Tag::str),
                                   value,
                                   _document.GetAllocator());
        }

        template<class T, class Tag>
        void end_object()
        {
            _cur_member = _iters.top();
            _iters.pop();
        }
    };

}} // namespace carbon::archive
