#ifndef CARBON_IO_UNCHECKED_MEMORY_HPP
#define CARBON_IO_UNCHECKED_MEMORY_HPP

#include "../detail/config.hpp"

#include <memory> // addressof
#include <cstring> // memcpy

namespace carbon::io {

    class unchecked_memory_input {
        const char* _buffer;

#ifdef CARBON_IO_TRACK_BYTES_COPIED
        std::size_t _bytes_copied = 0;
#endif

    public:
        constexpr static bool is_input_archive = true;
        using io_reference = CARBON_IO_REF_IF_BYTE_COUNT_TRACKED(unchecked_memory_input);

        constexpr unchecked_memory_input(const void* buffer) noexcept
            : _buffer(static_cast<const char*>(buffer))
        {}

        template<class T>
        void copy(T& value) noexcept
        {
            copy(value, sizeof(T));
        }

        template<class T>
        void copy(T& value, std::size_t size) noexcept
        {
            std::memcpy(::std::addressof(value), _buffer, size);
            _buffer += size;
#ifdef CARBON_IO_TRACK_BYTES_COPIED
            _copied += size;
#endif
        }

#ifdef CARBON_IO_TRACK_BYTES_COPIED
        std::size_t copied() const noexcept { return _bytes_copied; }
#endif
    };


    class unchecked_memory_output {
        char* _buffer;

#ifdef CARBON_IO_TRACK_BYTES_COPIED
        std::size_t _bytes_copied = 0;
#endif

    public:
        constexpr static bool is_input_archive = false;
        using io_reference                     = unchecked_memory_output&;

        constexpr unchecked_memory_output(void* buffer) noexcept
            : _buffer(static_cast<char*>(buffer))
        {}

        template<class T>
        void copy(const T& value) noexcept
        {
            copy(value, sizeof(T));
        }

        template<class T>
        void copy(const T& value, std::size_t size) noexcept
        {
            std::memcpy(_buffer, ::std::addressof(value), size);
            _buffer += size;
#ifdef CARBON_IO_TRACK_BYTES_COPIED
            _bytes_copied += size;
#endif
        }

#ifdef CARBON_IO_TRACK_BYTES_COPIED
        std::size_t copied() const noexcept { return _bytes_copied; }
#endif
    };

    struct unchecked_memory {
        using input  = unchecked_memory_input;
        using output = unchecked_memory_output;
    };

} // namespace carbon::io

#endif
