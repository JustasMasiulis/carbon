#pragma once
#include "meta.hpp"

namespace carbon { namespace archive {

    template<class Proxy>
    class binary {
        Proxy _proxy;

        template<class T, std::size_t N>
        void _add_array(T* arr, std::true_type /* raw serializable */)
        {
            p.copy(*arr, sizeof(T) * N);
        }

        template<class T, std::size_t N>
        void _add_array(T* arr, std::false_type /* not raw serializable */)
        {
            auto end = arr + N;
            for (; arr != end; ++arr)
                copy_one(*arr, p);
        }

    public:
        binary(Proxy&& proxy_init) : _proxy(std::move(proxy_init)) {}

        template<class T>
        void add(T& value)
        {
            _proxy.copy_raw(value, sizeof(value));
        }

        template<class T, std::size_t N>
        void add(T (&value)[N])
        {
            _add_array<T, N>(value, detail::is_raw_serializable<T>());
        }
    };

}} // namespace carbon::archive
