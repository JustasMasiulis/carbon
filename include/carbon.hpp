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
    CRBN_DETAIL_EXPAND(CARBON_NAMED_SERIALIZABLE_(__VA_ARGS__)(class_name, __VA_ARGS__))

namespace carbon {

    // TODO forceinline this
    /// \brief Constructs and returns an oject of type T using its constructor that
    /// accepts a carbon_type and the forwarded arguments
    /// ## usage
    /// ```cpp
    /// // will call foo::foo(foo::carbon_type<const foo, decltype(my_archive)&>, float)
    /// auto f = carbon::construct<foo>(my_archive, 5.0)
    /// ```
    // template<class T, class Archive, class... Args>
    // inline T construct(Archive& archive, Args&&... args);

    template<class T, class Archive>
    void serialize(T& this_ref, Archive& a)
    {
        detail::visit_members(this_ref, a);
    }

} // namespace carbon
