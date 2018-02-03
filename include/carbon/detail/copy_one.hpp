/*
 * Copyright 2018 Justas Masiulis
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include "serialization_tag.hpp"

namespace carbon { namespace detail {

    template<class Proxy, class T>
    void copy_size(T& value, Proxy p, std::true_type /* input proxy */)
    {
        typename T::size_type size;
        copy_one(size, p);
        value.resize(size);
    }

    template<class Proxy, class T>
    void copy_size(T& value, Proxy p, std::false_type /* output proxy */)
    {
        const auto size = value.size();
        copy_one(size, p);
    }

    template<class Proxy, class T, std::size_t N>
    void copy_array(T* arr, Proxy p, std::true_type /* raw serializable */)
    {
        p.copy(*arr, sizeof(T) * N);
    }

    template<class Proxy, class T, std::size_t N>
    void copy_array(T* arr, Proxy p, std::false_type /* not raw serializable */)
    {
        auto end = arr + N;
        for (; arr != end; ++arr)
            copy_one(*arr, p);
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


    template<class Proxy, class T>
    void copy_one(T& value, Proxy p, specialized_tag)
    {
        T::serializer_type::serialize(value, p);
    }

    template<class Proxy, class T>
    void copy_one(T& value, Proxy p, trivially_copyable_tag)
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

    template<class Proxy, class T, std::size_t N>
    void copy_one(T (&arr)[N], Proxy p)
    {
        copy_array<Proxy, T, N>(arr, p, std::is_fundamental<T>());
    }

    template<class Proxy, class T, std::size_t N>
    void copy_one(std::array<T, N>& arr, Proxy p)
    {
        copy_array<Proxy, T, N>(arr.data(), p, is_raw_serializable<T>());
    }

    template<class Proxy, class T>
    void copy_one(T& value, Proxy p)
    {
        copy_one(value, p, serialization_tag<T>());
    }

}} // namespace carbon::detail
