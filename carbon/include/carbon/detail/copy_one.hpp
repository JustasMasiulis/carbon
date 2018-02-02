#pragma once
#include <functional>
#include "meta.hpp"

namespace carbon { namespace detail {

    template<class Proxy, class T, class... Args>
    void copy_variadic(Proxy p, T& value, Args&... args)
    {
        copy_variadic(p, value);
        copy_variadic(p, args...);
    }

    template<class Proxy, class T>
    void copy_variadic(Proxy p, T& t)
    {
        copy_one(t, p);
    }

    template<class Proxy, class Tup, std::size_t... Is>
    void copy_tuple(Proxy p, Tup& t, std::index_sequence<Is...>)
    {
        copy_variadic(p, std::get<Is>(t)...);
    }

    template<class Proxy, class T>
    void copy_one(T& value, Proxy p)
    {
        using decayed = std::decay_t<T>;
        if constexpr (detail::is_serializer_specialized<decayed>::value)
            decayed::serializer_type::serialize(value, p);
        else if constexpr (std::is_fundamental<decayed>::value)
            p.copy(value, sizeof(T));
        else if constexpr (detail::is_iterable<decayed>::value) {
            using std::begin;
            using std::end;

            if constexpr (is_input_proxy<Proxy>::value) {
                typename T::size_type size;
                copy_one(size, p);

                value.resize(size);
            }
            else {
                auto size = value.size();
                copy_one(size, p);
            }

            auto first = begin(value);
            auto last  = end(value);

            for (; first != last; ++first)
                copy_one(*first, p);
        }
        else if constexpr (is_tuple_like<decayed>::value)
            copy_tuple(p, value, std::make_index_sequence<std::tuple_size<decayed>::value>());
        else
            static_assert(false);
    }

}} // namespace carbon::detail
