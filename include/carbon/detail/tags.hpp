#ifndef CARBON_DETAIL_TAGS_HPP
#define CARBON_DETAIL_TAGS_HPP

#include "traits.hpp"

#include <iterator>
#include <utility>

#include <string>
#include <vector>
#include <array>

namespace carbon { namespace detail {

    using std::begin;

    template<class T, class = void>
    struct is_iterable : std::false_type {};

    template<class T>
    struct is_iterable<T,
                       std::void_t<decltype(begin(std::declval<T&>())),
                                   decltype(end(std::declval<T&>()))>> : std::true_type {
    };

    template<class T>
    struct is_array : std::false_type {};

    template<class T, std::size_t N>
    struct is_array<std::array<T, N>> : std::true_type {};

    template<class T, std::size_t N>
    struct is_array<T[N]> : std::true_type {};


    template<class T>
    struct array_traits;

    template<class T, std::size_t N>
    struct array_traits<std::array<T, N>> {
        using value_type                  = T;
        constexpr static std::size_t size = N;
    };

    template<class T, std::size_t N>
    struct array_traits<T[N]> {
        using value_type                  = T;
        constexpr static std::size_t size = N;
    };


    template<class T>
    struct is_continguous : std::false_type {};

    template<class T, class CharTraits, class Alloc>
    struct is_continguous<std::basic_string<T, CharTraits, Alloc>> : std::true_type {};

    template<class T, class Alloc>
    struct is_continguous<std::vector<T, Alloc>> : std::true_type {};


    template<class T, class = void>
    struct is_tuple_like : std::false_type {};

    template<class T>
    struct is_tuple_like<T, std::void_t<std::tuple_size<T>>> : std::true_type {};

    namespace tag {

        struct specialized {};
        struct trivially_copyable {};
        struct array {};
        struct iterable {};
        struct continguos_iterable {};
        struct tuple_tag {};
        struct none {};

    } // namespace tag

    template<class T>
    inline constexpr auto serialization_tag() noexcept
    {
        if constexpr (traits::has_carbon_type<T>::value)
            return tag::specialized();
        else if constexpr (is_iterable<T>::value) {
            if constexpr (is_array<T>::value)
                return tag::array();
            else if constexpr (is_continguous<T>::value)
                return tag::continguos_iterable();
            else
                return tag::iterable();
        }
        else if constexpr (std::is_trivially_copyable_v<T>)
            return tag::trivially_copyable();
        else if constexpr (is_tuple_like<T>::value)
            return tag::tuple_tag();
        else
            return tag::none();
    }

}} // namespace carbon::detail

#endif // !CARBON_DETAIL_TAGS_HPP
