#pragma once
#include <functional>
#include "serialization_tag.hpp"

namespace carbon { namespace detail {

    template<class T, class Proxy>
    void copy_size(T& value, Proxy p, std::true_type)
    {
        typename T::size_type size;
        copy_one(size, p);
        value.resize(size);
    }

    template<class T, class Proxy>
    void copy_size(T& value, Proxy p, std::false_type)
    {
        const auto size = value.size();
        copy_one(size, p);
    }

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


    template<class T, class Proxy>
    void copy_one(T& value, Proxy p, specialized_tag)
    {
        T::serializer_type::serialize(value, p);
    }

    template<class T, class Proxy>
    void copy_one(T& value, Proxy p, fundamental_tag)
    {
        p.copy(value, sizeof(T));
    }

    template<class Proxy, class T>
    void copy_one(T& value, Proxy p, iterable_tag)
    {
        using std::begin;
        using std::end;

        copy_size(value, p, is_input_proxy<Proxy>());

        auto first = begin(value);
        auto last  = end(value);

        for (; first != last; ++first)
            copy_one(*first, p);
    }

    template<class Proxy, class T>
    void copy_one(T& value, Proxy p, tuple_tag)
    {
        copy_tuple(p, value, std::make_index_sequence<std::tuple_size<T>::value>());
    }

    template<class T, class Proxy>
    void copy_one(T& value, Proxy p)
    {
        copy_one(value, p, serialization_tag<T>());
    }

}} // namespace carbon::detail
