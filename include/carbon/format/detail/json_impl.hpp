#ifndef CARBON_FORMAT_JSON_IMPL_HPP
#define CARBON_FORMAT_JSON_IMPL_HPP

#include "../json.hpp"
#include "../../deps/rapidjson/include/rapidjson/document.h"
#include "../../deps/rapidjson/include/rapidjson/prettywriter.h"
#include "../../deps/rapidjson/include/rapidjson/ostreamwrapper.h"

#include "../../io/stream.hpp"

namespace carbon::detail::format {

    inline rapidjson::GenericStringRef<char> sv_to_sr(const std::string_view& sv)
    {
        // TODO add sanity check
        return { sv.data(), rapidjson::SizeType(sv.size()) };
    }

    template<class T>
    constexpr auto rapidjson_tag()
    {
        using ctype = typename T::template carbon_type<T>;
        if constexpr(ctype::named)
            return rapidjson::kObjectType;
        else
            return rapidjson::kArrayType;
    }

    void flush_to_io(carbon::io::stream_output& io, rapidjson::Document& doc)
    {
        rapidjson::OStreamWrapper                          osw(io.stream());
        rapidjson::PrettyWriter<rapidjson::OStreamWrapper> writer(osw);
        doc.Accept(writer);
    }

    template<class Tag, class Derived>
    struct json_base;

    template<class Derived>
    struct json_base<io::output_io_tag, Derived> {
        rapidjson::Document             _document;
        rapidjson::Document::ValueType* _cur_member;

        using json_value = rapidjson::Document::ValueType;

        template<class T>
        using value_ref =
            typename io::detail::io_value_reference<io::input_io_tag, T>::ref;

        Derived& derived() { return *static_cast<Derived*>(this); }

        json_base() : _document(rapidjson::kArrayType), _cur_member(&_document) {}
        json_base(const json_base&) = default;
        json_base(json_base&&)      = default;

        ~json_base() { flush_to_io(derived().io(), _document); }

        rapidjson::Document::ValueType* last_member()
        {
            return &((--_cur_member->MemberEnd())->value);
        }

        json_value* last_array_value() { return (_cur_member->End() - 1); }

        template<class T>
        inline void copy_dispatch(value_ref<T>& value)
        {
            copy_dispatch<T>(value, detail::simplified_serialization_tag<T>());
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>& value, std::string_view name)
        {
            copy_dispatch<T>(value, name, detail::simplified_serialization_tag<T>());
        }

        template<class T>
        void copy_specialized(value_ref<T>& value, json_value* new_cur_member)
        {
            auto old = std::exchange(_cur_member, new_cur_member);

            members_for_each<T, detail::members_visitor_t>::visit(value, derived());

            _cur_member = old;
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>&    value,
                                  std::string_view name,
                                  detail::tag::specialized)
        {
            _cur_member->AddMember(sv_to_sr(name),
                                   json_value{ rapidjson_tag<T>() },
                                   _document.GetAllocator());
            copy_specialized<T>(value, last_member());
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>& value, detail::tag::specialized)
        {
            _cur_member->PushBack(json_value{ rapidjson_tag<T>() },
                                  _document.GetAllocator());
            copy_specialized<T>(value, last_array_value());
        }

        template<class T>
        void copy_magic(value_ref<T>& value, json_value* new_cur_member)
        {
            auto old = std::exchange(_cur_member, new_cur_member);

            detail::members_for_each<value_ref<T>&,
                                     detail::magic_members_visitor_t>::visit(value,
                                                                             derived());
            _cur_member = old;
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>& value, detail::tag::none)
        {
            _cur_member->PushBack(json_value{ rapidjson::kArrayType },
                                  _document.GetAllocator());

            copy_magic<T>(value, last_array_value());
        }

        template<class T>
        inline void
        copy_dispatch(value_ref<T>& value, std::string_view name, detail::tag::none)
        {
            _cur_member->AddMember(sv_to_sr(name),
                                   json_value{ rapidjson::kArrayType },
                                   _document.GetAllocator());

            copy_magic<T>(value, last_member());
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>& value, detail::tag::trivially_copyable)
        {
            _cur_member->PushBack(value, _document.GetAllocator());
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>&    value,
                                  std::string_view name,
                                  detail::tag::trivially_copyable)
        {
            _cur_member->AddMember(sv_to_sr(name), value, _document.GetAllocator());
        }

        template<class T>
        void copy_iterable(value_ref<T>& value, json_value* new_cur_member)
        {
            using std::begin;
            using std::end;

            auto old = std::exchange(_cur_member, new_cur_member);

            std::for_each(begin(value), end(value), std::ref(derived()));

            _cur_member = old;
        }

        template<class T>
        inline void
        copy_dispatch(value_ref<T>& value, std::string_view name, detail::tag::iterable)
        {
            _cur_member->AddMember(sv_to_sr(name),
                                   json_value{ rapidjson::kArrayType },
                                   _document.GetAllocator());

            copy_iterable<T>(value, last_member());
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>& value, detail::tag::iterable)
        {
            _cur_member->PushBack(json_value{ rapidjson::kArrayType },
                                  _document.GetAllocator());

            copy_iterable<T>(value, last_array_value());
        }

        template<class T>
        void copy_tuple(value_ref<T>& value, json_value* new_cur_member)
        {
            auto old = std::exchange(_cur_member, new_cur_member);

            std::apply(derived(), value);

            _cur_member = old;
        }

        template<class T>
        inline void
        copy_dispatch(value_ref<T>& value, std::string_view name, detail::tag::tuple)
        {
            _cur_member->AddMember(sv_to_sr(name),
                                   json_value{ rapidjson::kArrayType },
                                   _document.GetAllocator());

            copy_tuple<T>(value, last_member());
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>& value, detail::tag::tuple)
        {
            _cur_member->PushBack(json_value{ rapidjson::kArrayType },
                                  _document.GetAllocator());

            copy_tuple<T>(value, last_array_value());
        }
    };

} // namespace carbon::detail::format

#endif
