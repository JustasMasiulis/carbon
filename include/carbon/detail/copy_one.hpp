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
#include "proxy_tags.hpp"

namespace carbon { namespace detail {

    template<class Archive, class T>
    void copy_size(T& value, Archive& a, std::true_type /* input Archive */)
    {
        typename T::size_type size;
        copy_one(size, a);
        value.resize(size);
    }

    template<class Archive, class T>
    void copy_size(T& value, Archive& a, std::false_type /* output Archive */)
    {
        auto size = value.size();
        copy_one(size, a);
    }

    template<class Archive, class T, class... Args>
    void copy_variadic(Archive p, T& value, Args&... args)
    {
        copy_variadic(p, value);
        copy_variadic(p, args...);
    }

    template<class Archive, class T>
    void copy_variadic(Archive p, T& t)
    {
        copy_one(t, p);
    }

    template<class Archive, class Tup, std::size_t... Is>
    void copy_tuple(Archive p, Tup& t, std::index_sequence<Is...>)
    {
        copy_variadic(p, std::get<Is>(t)...);
    }


    template<class Archive, class T>
    void copy_one(T& value, Archive p, specialized_tag)
    {
        T::serializer_type::serialize(value, p);
    }

    template<class Archive, class T>
    void copy_one(T& value, Archive a, trivially_copyable_tag)
    {
        a.add(value);
    }

    template<class Archive, class T>
    void copy_one(T& value, Archive& a, iterable_tag)
    {
        using std::begin;
        using std::end;

        copy_size(value, a, Archive::is_input<Archive>());

        auto first = begin(value);
        auto last  = end(value);

        for (; first != last; ++first)
            copy_one(*first, a, serialization_tag<std::decay_t<decltype(*first)>>());
    }

    template<class Archive, class T>
    void copy_one(T& value, Archive& a, tuple_tag)
    {
        copy_tuple(a, value, std::make_index_sequence<std::tuple_size<T>::value>());
    }

    /*template<class Archive, class T, std::size_t N>
    void copy_one(T (&arr)[N], Archive& a)
    {
        copy_array<Archive, T, N>(arr, a, is_raw_serializable<T>());
    }*/

    /*template<class Archive, class T, std::size_t N>
    void copy_one(std::array<T, N>& arr, Archive& a)
    {
        copy_array<Archive, T, N>(arr.data(), a, is_raw_serializable<T>());
    }*/

    template<class Archive, class T>
    void copy_one(T& value, Archive& a)
    {
        copy_one(value, a, serialization_tag<T>());
    }

}} // namespace carbon::detail
