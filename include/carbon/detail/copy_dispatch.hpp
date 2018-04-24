#ifndef CARBON_DETAIL_COPY_DISPATCH_HPP
#define CARBON_DETAIL_COPY_DISPATCH_HPP

#include "visit_members.hpp"

namespace carbon { namespace detail {

    template<class T, class Archive>
    inline void copy_dispatch (T& value, Archive& a);

    template<class T, class Archive>
    inline void copy_dispatch (T& value, Archive& a, tag::specialized)
    {
        constexpr auto size =
            std::tuple_size<T::template carbon_type<T>::target_members>::value;
        members_for_each<T, Archive, members_visitor_t, size>::visit (value, a);
    }

    template<class T, class Archive>
    inline void copy_dispatch (T& value, Archive& a, tag::none)
    {
        constexpr auto size = boost::pfr::detail::fields_count<T> ();
        members_for_each<T, Archive, magic_members_visitor_t, size>::visit (value, a);
    }

    template<class T, class Archive>
    inline void copy_dispatch (T& value, Archive& a, tag::trivially_copyable)
    {
        a.copy (value);
    }

    template<class T, class Archive>
    inline void copy_dispatch (T& value, Archive& a, tag::array)
    {
        using value_type = std::remove_reference_t<decltype (value[0])>;
        if constexpr (std::is_same_v<serialization_tag_t<value_type>,
                                     tag::trivially_copyable>)
            a.copy (*std::begin (value), sizeof (T));
        else {
            auto       first = std::begin (value);
            const auto last  = std::end (value);
            for (; first != last; ++first)
                copy_dispatch (*first, a);
        }
    }

    template<class T, class Archive>
    inline void copy_dispatch (T& value, Archive& a, tag::continguos_iterable)
    {
        // continguos_iterable is only string and vector - no need for ADL stuff
        std::uint32_t size;
        if constexpr (Archive::is_input_archive) {
            a.copy (size);
            value.resize (size);
        }

        if constexpr (std::is_same_v<serialization_tag_t<typename T::value_type>,
                                     tag::trivially_copyable>) {
            if constexpr (!Archive::is_input_archive) {
                size = static_cast<std::uint32_t> (value.size ());
                a.copy (size);
            }
            a.copy (value.front (), size * sizeof (typename T::value_type));
        }
        else {
            auto       first = value.begin ();
            const auto last  = value.end ();
            if constexpr (!Archive::is_input_archive)
                a.copy (static_cast<std::uint32_t> (last - first));

            for (; first != last; ++first)
                copy_dispatch (*first, a);
        }
    }

    template<class T, class Archive>
    inline void copy_dispatch (T& value, Archive& a, tag::iterable)
    {
        using std::begin;
        using std::end;
        using std::size;

        if constexpr (Archive::is_input_archive) {
            std::uint32_t size;
            a.copy (size);

            while (size--) {
                if constexpr (traits::has_emplace_back<T>::value)
                    copy_dispatch (value.emplace_back (), a);
                else // TODO save the iterator
                    copy_dispatch (*value.emplace (end (value)), a);
            }
        }
        else {
            auto       first = begin (value);
            const auto last  = end (value);
            a.copy (static_cast<std::uint32_t> (size (value)));
            for (; first != last; ++first)
                copy_dispatch (*first, a);
        }
    }

    template<class Archive, class T, class... Args>
    inline void copy_dispatch_variadic (Archive& a, T& value, Args&... args)
    {
        copy_dispatch (value, a);
        copy_dispatch_variadic (a, args...);
    }

    template<class Archive, class T>
    inline void copy_dispatch_variadic (Archive& a, T& value)
    {
        copy_dispatch (value, a);
    }

    template<class Archive, class Tup, std::size_t... Is>
    inline void copy_dispatch_tuple (Tup& tuple, Archive& a, std::index_sequence<Is...>)
    {
        copy_dispatch_variadic (a, std::get<Is> (tuple)...);
    }

    template<class T, class Archive>
    inline void copy_dispatch (T& value, Archive& a, tag::tuple)
    {
        constexpr std::size_t size = std::tuple_size<T>::value;
        copy_dispatch_tuple (value, a, std::make_index_sequence<size> ());
    }

    template<class T, class Archive>
    void copy_dispatch (T& value, Archive& a)
    {
        constexpr auto tag = detail::serialization_tag<T> ();
        copy_dispatch (value, a, tag);
    }

}} // namespace carbon::detail

#endif // !CARBON_DETAIL_COPY_DISPATCH_HPP
