#ifndef CARBON_DETAIL_COPY_DISPATCH_HPP
#define CARBON_DETAIL_COPY_DISPATCH_HPP

#include "visit_members.hpp"

namespace carbon { namespace detail {

    template<class T, class Archive>
    inline void copy_dispatch(T& value, Archive& a, tag::specialized)
    {
        constexpr auto size =
            std::tuple_size<T::template carbon_type<T>::target_members>::value;
        members_visitor_t<T, Archive, size>::visit(this_ref, archive);
    }

    template<class T, class Archive>
    inline void copy_dispatch(T& value, Archive& a, tag::none)
    {
        constexpr auto size = boost::pfr::detail::fields_count<T>();
        magic_members_visitor_t<T, Archive, size>::visit(value, a);
    }

    template<class T, class Archive>
    inline void copy_dispatch(T& value, Archive& a, tag::trivially_copyable)
    {
        a.copy(value);
    }

    template<class T, class Archive>
    inline void copy_dispatch(T& value, Archive& a, tag::array)
    {
        using std::begin;
        using std::end;
        using type = std::remove_reference_t<decltype(*begin(value))>;

        constexpr auto type_tag = serialization_tag<type>();
        if constexpr (std::is_same_v<std::decay_t<decltype(type_tag)>,
                                     tag::trivially_copyable>)
            a.copy(*begin(value), sizeof(T));
        else {
            auto       first = begin(value);
            const auto last  = end(value);
            for (; first != last; ++first)
                copy_dispatch(*first, a, type_tag);
        }
    }

    template<class T, class Archive>
    inline void copy_dispatch(T& value, Archive& a, tag::continguos_iterable)
    {
        std::uint32_t size;
        if constexpr (Archive::is_input_archive) {
            a.copy(size);
            value.resize(size);
        }

        constexpr auto type_tag = serialization_tag<T::value_type>();
        if constexpr (std::is_same_v<std::decay_t<decltype(type_tag)>,
                                     tag::trivially_copyable>) {
            if constexpr (!Archive::is_input_archive) {
                size = static_cast<std::uint32_t>(value.size());
                a.copy(size);
            }
            a.copy(value.front(), size * sizeof(T::value_type));
        }
        else {
            auto       first = value.begin();
            const auto last  = value.end();
            if constexpr (!Archive::is_input_archive)
                a.copy(static_cast<std::uint32_t>(last - first));

            for (; first != last; ++first)
                copy_dispatch(*first, a, type_tag);
        }
    }

    template<class T, class Archive>
    inline void copy_dispatch(T& value, Archive& a, tag::iterable)
    {
        using std::end;
        constexpr auto tag = serialization_tag<T::value_type>();
        if constexpr (Archive::is_input_archive) {
            std::uint32_t size;
            a.copy(size);
            while (size--) {
                if constexpr (traits::has_emplace_back<T>::value)
                    copy_dispatch(value.emplace_back(), a, tag);
                else // TODO save the iterator
                    copy_dispatch(*value.emplace(end(value)), a, tag);
            }
        }
        else {
            using std::begin;
            using std::size;

            auto       first = begin(value);
            const auto last  = end(value);
            a.copy(static_cast<std::uint32_t>(size(value)));
            for (; first != last; ++first)
                copy_dispatch(*first, a, tag);
        }
    }

    template<class T, class Archive>
    inline void copy_dispatch(T& value, Archive& a, tag::tuple)
    {
        throw std::runtime_error("not implemented");
    }

}} // namespace carbon::detail

#endif // !CARBON_DETAIL_COPY_DISPATCH_HPP
