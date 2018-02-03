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
#include <type_traits>
#include <iterator>

namespace carbon { namespace detail {

    template<typename T, typename = void>
    struct is_iterable : std::false_type {};

    template<typename T>
    struct is_iterable<T,
                       std::void_t<decltype(begin(std::declval<T>())),
                                   decltype(begin(std::declval<T>()))>>
        : std::true_type {};

    template<typename T, typename = void>
    struct is_serializer_specialized : std::false_type {};

    template<typename T>
    struct is_serializer_specialized<T, std::void_t<typename T::serializer_type>>
        : std::true_type {};

    template<typename T, typename = void>
    struct is_tuple_like : std::false_type {};

    template<typename T>
    struct is_tuple_like<T, std::void_t<decltype(std::tuple_size<T>::value)>>
        : std::true_type {};

    template<class T>
    struct is_raw_serializable
        : std::integral_constant<bool,
                                 !is_serializer_specialized<T>::value &&
                                     std::is_trivially_copyable<T>::value> {};

}} // namespace carbon::detail
