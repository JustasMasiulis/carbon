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
#include "carbon/detail/generated_macros.hpp"
#include "carbon/detail/util_macros.hpp"
#include <utility>

// needed to fix msvc va args expansion
#define CRBN_DETAIL_EXPAND(...) __VA_ARGS__

#define CARBON_SERIALIZABLE_(...) \
    CRBN_DETAIL_CAT(CRBN_DETAIL_SERIALIZABLE_, CRBN_DETAIL_NARGS(__VA_ARGS__))

#define CARBON_NAMED_SERIALIZABLE_(...) \
    CRBN_DETAIL_CAT(CRBN_DETAIL_NAMED_SERIALIZABLE_, CRBN_DETAIL_NARGS(__VA_ARGS__))

#define CARBON_SERIALIZABLE(class_name, ...) \
    CRBN_DETAIL_EXPAND(CARBON_SERIALIZABLE_(__VA_ARGS__)(class_name, __VA_ARGS__))

#define CARBON_NAMED_SERIALIZABLE(class_name, ...) \
    CRBN_DETAIL_EXPAND(                            \
        CARBON_NAMED_SERIALIZABLE_(__VA_ARGS__)(class_name, __VA_ARGS__))

namespace carbon {

    template<class T, class Archive, class... Args>
    inline T construct(Archive& archive, Args&&... args)
    {
        using carbon_type = typename T::template carbon_type<const T, Archive&>;

        typename std::aligned_storage<sizeof(T), alignof(T)>::type storage;
        ::new (static_cast<void*>(&storage))
            T(carbon_type{ reinterpret_cast<const T*>(&storage), archive },
              std::forward<Args>(args)...);

        return *reinterpret_cast<T*>(&storage);
    }

} // namespace carbon
