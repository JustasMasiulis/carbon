#pragma once
#include "copy_one.hpp"
#include <iostream>

namespace carbon {

    namespace detail {

        struct istream_proxy {
            std::istream& in;
            using proxy_tag = input_proxy_tag;

            template<class T>
            void copy(T& data, std::size_t size)
            {
                in.read(reinterpret_cast<char*>(::std::addressof<T>(data)), size);
            }
        };

        struct ostream_proxy {
            std::ostream& out;
            using proxy_tag = output_proxy_tag;

            template<class T>
            void copy(const T& data, std::size_t size)
            {
                out.write(reinterpret_cast<const char*>(::std::addressof(data)), size);
            }
        };

    } // namespace detail

    template<class T>
    void serialize(T& value, std::ostream& out)
    {
        detail::ostream_proxy proxy{ out };
        detail::copy_one(value, proxy);
    }

    template<class T>
    void deserialize(T& value, std::istream& in)
    {
        detail::istream_proxy proxy{ in };
        detail::copy_one(value, proxy);
    }

} // namespace carbon
