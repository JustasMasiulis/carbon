// Copyright (c) 2016-2017 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_SEQUENCE_TUPLE_HPP
#define BOOST_PFR_DETAIL_SEQUENCE_TUPLE_HPP
#pragma once

#include <utility> // metaprogramming stuff
#include <cstddef> // std::size_t

///////////////////// Tuple that holds it's values in the supplied order
namespace carbon::detail::pfr {

    template<std::size_t N, class T>
    struct base_from_member {
        T value;
    };

    template<class I, class... Tail>
    struct tuple_base;

    template<std::size_t... I, class... Tail>
    struct tuple_base<std::index_sequence<I...>, Tail...> : base_from_member<I, Tail>... {
        static constexpr std::size_t size_v = sizeof...(I);

        // We do not use `noexcept` in the following functions, because if user forget to
        // put one then clang will issue an error: "error: exception specification of
        // explicitly defaulted default constructor does not match the calculated one".
        constexpr tuple_base()                  = default;
        constexpr tuple_base(tuple_base&&)      = default;
        constexpr tuple_base(const tuple_base&) = default;

        constexpr tuple_base(Tail... v) noexcept : base_from_member<I, Tail>{ v }... {}
    };

    template<>
    struct tuple_base<std::index_sequence<>> {
        static constexpr std::size_t size_v = 0;
    };

    template<std::size_t N, class T>
    constexpr T& get_impl(base_from_member<N, T>& t) noexcept
    {
        return t.value;
    }

    template<std::size_t N, class T>
    constexpr const T& get_impl(const base_from_member<N, T>& t) noexcept
    {
        return t.value;
    }

    template<std::size_t N, class T>
    constexpr T&& get_impl(base_from_member<N, T>&& t) noexcept
    {
        return std::forward<T>(t.value);
    }


    template<class... Ts>
    struct tuple : tuple_base<std::make_index_sequence<sizeof...(Ts)>, Ts...> {
        using tuple_base<std::make_index_sequence<sizeof...(Ts)>, Ts...>::tuple_base;
    };


    template<std::size_t N, class... T>
    constexpr decltype(auto) get(tuple<T...>& t) noexcept
    {
        static_assert(N < tuple<T...>::size_v, "Tuple index out of bounds");
        return get_impl<N>(t);
    }

    template<std::size_t N, class... T>
    constexpr decltype(auto) get(const tuple<T...>& t) noexcept
    {
        static_assert(N < tuple<T...>::size_v, "Tuple index out of bounds");
        return get_impl<N>(t);
    }

    template<std::size_t N, class... T>
    constexpr decltype(auto) get(tuple<T...>&& t) noexcept
    {
        static_assert(N < tuple<T...>::size_v, "Tuple index out of bounds");
        return get_impl<N>(std::move(t));
    }

    template<std::size_t I, class T>
    using tuple_element =
        std::remove_reference<decltype(::boost::pfr::get<I>(std::declval<T>()))>;

    // only for member pointers
    template<class... Args>
    constexpr inline auto make_tuple(Args... args)
    {
        return tuple<Args...>(args...);
    }

} // namespace carbon::detail::pfr

#endif // BOOST_PFR_CORE_HPP
