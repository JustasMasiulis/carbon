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
#include "detail/copy_dispatch.hpp"

namespace carbon {

    template<class Derived>
    struct archive_base {
        template<class... Args>
        inline void operator()(Args&... args)
        {
            _copy_all(args...);
        }

    private:
        template<class T, class... Rest>
        inline void _copy_all(T& value, Rest&... rest)
        {
            _copy_all(value);
            _copy_all(rest...);
        }

        template<class T>
        inline void _copy_all(T& value)
        {
            constexpr auto tag = detail::serialization_tag<T>();
            detail::copy_dispatch(value, *static_cast<Derived*>(this), tag);
        }
    };

} // namespace carbon
