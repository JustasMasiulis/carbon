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
#include "copy_one.hpp"
#include <iostream>

namespace carbon {

    namespace proxy {

        struct istream_proxy {
            std::istream& in;
            using proxy_category = input_proxy_tag;

            template<class T>
            void copy(T& data, std::size_t size)
            {
                in.read(reinterpret_cast<char*>(::std::addressof<T>(data)), size);
            }
        };

        struct ostream_proxy {
            std::ostream& out;
            using proxy_category = output_proxy_tag;

            template<class T>
            void copy(const T& data, std::size_t size)
            {
                out.write(reinterpret_cast<const char*>(::std::addressof(data)),
                          size);
            }
        };

    } // namespace proxy

    template<class T>
    void serialize(T& value, std::ostream& out)
    {
        proxy::ostream_proxy proxy{ out };
        detail::copy_one(value, proxy);
    }

    template<class T>
    void deserialize(T& value, std::istream& in)
    {
        proxy::istream_proxy proxy{ in };
        detail::copy_one(value, proxy);
    }

} // namespace carbon
