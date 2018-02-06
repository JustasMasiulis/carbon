#pragma once
#include <cstddef>

#define CRBN_STRING_EXPAND_10(n, x)                                             \
    ::crbn_::c_at<n##0>(x), ::crbn_::c_at<n##1>(x), ::crbn_::c_at<n##2>(x),     \
        ::crbn_::c_at<n##3>(x), ::crbn_::c_at<n##4>(x), ::crbn_::c_at<n##5>(x), \
        ::crbn_::c_at<n##6>(x), ::crbn_::c_at<n##7>(x), ::crbn_::c_at<n##8>(x), \
        ::crbn_::c_at<n##9>(x)

#define CRBN_STRING_EXPAND_50(x)                                  \
    CRBN_STRING_EXPAND_10(, x), CRBN_STRING_EXPAND_10(1, x),      \
        CRBN_STRING_EXPAND_10(2, x), CRBN_STRING_EXPAND_10(3, x), \
        CRBN_STRING_EXPAND_10(4, x)

#define CRBN_STR(s)                                                \
    ::carbon::detail::string_builder<::carbon::detail::tstring_<>, \
                                     CRBN_STRING_EXPAND_50(s)>::type

namespace crbn_ {

    template<std::size_t Idx, std::size_t M>
    constexpr char c_at(const char (&str)[M]) noexcept
    {
        static_assert(M <= 50, "serializable member name too large.");
        return (Idx < M) ? str[Idx] : 0;
    }

} // namespace crbn_

namespace carbon { namespace detail {

    template<typename, char...>
    struct string_builder;

    template<typename T>
    struct string_builder<T> {
        using type = T;
    };

    template<template<char...> class S, char... Hs, char C, char... Cs>
    struct string_builder<S<Hs...>, C, Cs...>
        : std::conditional<C == '\0',
                           string_builder<S<Hs...>>,
                           string_builder<S<Hs..., C>, Cs...>>::type {};

    template<char... Cs>
    struct tstring_ {
        static constexpr std::size_t size          = sizeof...(Cs);
        constexpr static char        str[size + 1] = { Cs..., '\0' };
    };

}} // namespace carbon::detail
