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
#include "carbon/detail/nargs_macro.hpp"
#include "carbon/serializer.hpp"
#include "carbon/proxies.hpp"

// needed to fix msvc va args expansion
#define CRBN_DETAIL_EXPAND(...) __VA_ARGS__

#define CARBON_SERIALIZABLE_(...) \
    CRBN_DETAIL_CAT(CRBN_DETAIL_SERIALIZABLE_, CRBN_DETAIL_NARGS(__VA_ARGS__))

#define CARBON_SERIALIZABLE(class_name, ...)    \
    using serializer_type = CRBN_DETAIL_EXPAND( \
        CARBON_SERIALIZABLE_(__VA_ARGS__)(class_name, __VA_ARGS__))
