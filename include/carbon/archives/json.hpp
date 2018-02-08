#pragma once
#define RAPIDJSON_HAS_STDSTRING 1
#include "deps/rapidjson/document.h"
#include "../detail/serialization_tag.hpp"
#include "deps/rapidjson/prettywriter.h"
#include "deps/rapidjson/istreamwrapper.h"
#include <stack>

namespace carbon { namespace archive {

    class json_input {
        rapidjson::Document                             _document;
        std::stack<rapidjson::Document::MemberIterator> _members;
        rapidjson::Document::MemberIterator             _current;

    public:
        using archive_category_tag = detail::input_archive_tag;

        json_input(std::istream& stream)
        {
            rapidjson::IStreamWrapper stream_wrap(stream);
            _document.ParseStream(stream_wrap);
            _current = _document.MemberBegin();
        }

        template<class T, class Tag>
        void begin_object()
        {
            _members.push(_current);
            _current = _current->value.MemberBegin();
        }

        template<class T, class Tag>
        void copy(T& value)
        {
            value = _current->value.Get<T>();
            ++_current;
        }

        template<class T, class Tag>
        void end_object()
        {
            _current = _members.top();
            _members.pop();
        }
    };

    class json_output {
        std::ostream&                               _stream;
        rapidjson::Document                         _document;
        std::stack<rapidjson::Document::ValueType*> _iters;
        rapidjson::Document::ValueType*             _cur_member;

        using json_value = rapidjson::Document::ValueType;

        template<class T>
        void _push_value(const T& value, json_value& member, detail::iterable_tag)
        {
            using std::begin;
            using std::end;

            member.PushBack(json_value{ rapidjson::kArrayType },
                            _document.GetAllocator());

            auto last_member = member.End() - 1;

            last_member->Reserve(static_cast<rapidjson::SizeType>(value.size()),
                                 _document.GetAllocator());

            auto       first = begin(value);
            const auto last  = end(value);
            using val_type   = std::decay_t<decltype(*first)>;
            for (; first != last; ++first)
                _push_value(
                    *first, *last_member, detail::serialization_tag<val_type>());
        }

        template<class T>
        void _push_value(const T&    value,
                         json_value& member,
                         detail::trivially_copyable_tag)
        {
            member.PushBack(value, _document.GetAllocator());
        }

        void _push_value(const std::string& value,
                         json_value&        member,
                         detail::iterable_tag)
        {
            member.PushBack(
                rapidjson::GenericStringRef<char>(
                    value.c_str(), static_cast<rapidjson::SizeType>(value.size())),
                _document.GetAllocator());
        }

        template<class T>
        void _push_value(const T& value, json_value& member, detail::tuple_tag)
        {
            member.PushBack(json_value{ rapidjson::kArrayType },
                            _document.GetAllocator());

            auto old_member = _cur_member;
            _cur_member     = (member.End() - 1);
            _copy_tuple(value,
                        std::make_index_sequence<std::tuple_size<T>::value>());
            _cur_member = old_member;
        }

        template<class T>
        void _push_value(const T& value, json_value& member, detail::specialized_tag)
        {
            member.PushBack(rapidjson::Document::ValueType{ rapidjson::kObjectType },
                            _document.GetAllocator());
            auto old    = _cur_member;
            _cur_member = (member.End() - 1);
            T::serializer_type::serialize<T>(value, *this);
            _cur_member = old;
        }

        template<class T, class... Args>
        void _copy_variadic(const T& value, const Args&... args)
        {
            _copy_variadic(value);
            _copy_variadic(args...);
        }

        template<class T>
        void _copy_variadic(const T& val)
        {
            _push_value(val, *_cur_member, detail::serialization_tag<T>());
        }

        template<class Tup, std::size_t... Is>
        void _copy_tuple(const Tup& t, std::index_sequence<Is...>)
        {
            _copy_variadic(std::get<Is>(t)...);
        }


        template<class T, class Tag>
        void _add_member(const T& value, detail::iterable_tag)
        {
            using std::begin;
            using std::end;

            _cur_member->AddMember(
                Tag::str,
                rapidjson::Document::ValueType{ rapidjson::kArrayType },
                _document.GetAllocator());
            auto& member = last_member();
            member.Reserve(static_cast<rapidjson::SizeType>(value.size()),
                           _document.GetAllocator());

            auto       first = begin(value);
            const auto last  = end(value);
            using val_type   = std::decay_t<decltype(*first)>;
            for (; first != last; ++first)
                _push_value(*first, member, detail::serialization_tag<val_type>());
        }

        template<class T, class Tag>
        void _add_member(const T& value, detail::tuple_tag)
        {
            _cur_member->AddMember(
                Tag::str,
                rapidjson::Document::ValueType{ rapidjson::kArrayType },
                _document.GetAllocator());
            auto old_member = _cur_member;
            _cur_member     = &last_member();
            _copy_tuple(value,
                        std::make_index_sequence<std::tuple_size<T>::value>());
            _cur_member = old_member;
        }

        template<class T, class Tag>
        void _add_member(const T& value, detail::trivially_copyable_tag)
        {
            _cur_member->AddMember(rapidjson::GenericStringRef<char>(Tag::str),
                                   value,
                                   _document.GetAllocator());
        }

        rapidjson::Document::ValueType& last_member()
        {
            return (--_cur_member->MemberEnd())->value;
        }

    public:
        using archive_category_tag = detail::output_archive_tag;
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
            _cur_member->AddMember(
                rapidjson::GenericStringRef<char>(Tag::str),
                rapidjson::Document::ValueType(rapidjson::kObjectType),
                _document.GetAllocator());
            _iters.push(_cur_member);
            _cur_member = &((--_cur_member->MemberEnd())->value);
        }

        template<class Tag, class T>
        void copy(const T& value)
        {
            _add_member<T, Tag>(value, detail::serialization_tag<T>());
        }

        template<class Tag>
        void copy(const std::string& value)
        {
            _cur_member->AddMember(
                Tag::str,
                rapidjson::GenericStringRef<char>(
                    value.c_str(),
                    static_cast<rapidjson::SizeType>(value.size())) );
        }

        template<class T, class Tag>
        void end_object()
        {
            _cur_member = _iters.top();
            _iters.pop();
        }
    };

}} // namespace carbon::archive
