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
#include "meta.hpp"

namespace carbon { namespace detail {

    struct specialized_tag {};
    struct fundamental_tag {};
    struct iterable_tag {};
    struct tuple_tag {};
    struct array_tag {};

    // I know it's ugly, okay
    template<class T>
    using serialization_tag = std::conditional_t<
        std::is_fundamental<T>::value,
        fundamental_tag,
        std::conditional_t<
            is_serializer_specialized<T>::value,
            specialized_tag,
            std::conditional_t<
                is_iterable<T>::value,
                iterable_tag,
                std::conditional_t<is_tuple_like<T>::value, tuple_tag, void>>>>;

}} // namespace carbon::detail
