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
        if constexpr (std::is_same_v<decltype(type_tag), tag::trivially_copyable>)
            a.copy(*begin(value), traits::size_getter<T>::get(value) * sizeof(T));
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
        using std::begin;
        using std::end;
        using type = std::remove_reference_t<decltype(*begin(value))>;

        constexpr auto type_tag = serialization_tag<type>();
        if constexpr (std::is_same_v<decltype(type_tag), tag::trivially_copyable>) {
            const auto size = traits::size_getter<T>::get(value);
            a.copy(size);
            a.copy(*begin(value), size * sizeof(T));
        }
        else {
            auto       first = begin(value);
            const auto last  = end(value);
            auto       size  = static_cast<std::uint32_t>(last - first);
            a.copy(size);
            for (; first != last; ++first)
                copy_dispatch(*first, a, type_tag);
        }
    }

    template<class T, class Archive>
    inline void copy_dispatch(T& value, Archive& a, tag::iterable)
    {
        using std::begin;
        using std::end;

        auto       first = begin(value);
        const auto last  = end(value);
        auto       size  = static_cast<std::uint32_t>(last - first);
        a.copy(size);

        for (; first != last; ++first)
            visit_members(*first, a);
    }

    template<class T, class Archive>
    inline void copy_dispatch(T& value, Archive& a, tag::tuple)
    {
        throw std::runtime_error("not implemented");
    }

}} // namespace carbon::detail

#endif // !CARBON_DETAIL_COPY_DISPATCH_HPP
