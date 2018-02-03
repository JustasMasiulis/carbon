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

        struct imemory_proxy {
            std::uint8_t* ptr;
            std::uint8_t* end;
            using proxy_category = proxy::input_proxy_tag;

            template<class T>
            void copy(T& data, std::size_t size) noexcept
            {
                auto temp = ptr;
                ptr += size;
                if (ptr > end)
                    throw std::runtime_error("carbon input proxy out of bounds");

                std::memcpy(::std::addressof(data),temp, size);
            }
        };

        struct omemory_proxy {
            std::uint8_t* ptr;
            std::uint8_t* end;
            using proxy_category = proxy::output_proxy_tag;

            template<class T>
            void copy(const T& data, std::size_t size) noexcept
            {
                auto temp = ptr;
                ptr += size;
                if (ptr > end)
                    throw std::runtime_error("carbon output proxy out of bounds");

                std::memcpy(temp, ::std::addressof(data), size);
            }
        };

        struct unsafe_imemory_proxy {
            const std::uint8_t*& ptr;
            using proxy_category = proxy::input_proxy_tag;

            template<class T>
            void copy(T& data, std::size_t size) noexcept
            {
                std::memcpy(::std::addressof(data), ptr, size);
                ptr += size;
            }
        };

        struct unsafe_omemory_proxy {
            std::uint8_t*& ptr;
            using proxy_category = proxy::output_proxy_tag;

            template<class T>
            void copy(const T& data, std::size_t size) noexcept
            {
                std::memcpy(ptr, ::std::addressof(data), size);
                ptr += size;
            }
        };

    } // namespace detail

    template<class T>
    std::ptrdiff_t serialize(T& value, std::uint8_t* buffer)
    {
        auto temp = buffer;
        proxy::unsafe_omemory_proxy proxy{ buffer };
        detail::copy_one(value, proxy);
        return buffer - temp;
    }

    template<class T>
    void deserialize(T& value, const std::uint8_t* buffer)
    {
        proxy::unsafe_imemory_proxy proxy{ buffer };
        detail::copy_one(value, proxy);
    }

} // namespace carbon
