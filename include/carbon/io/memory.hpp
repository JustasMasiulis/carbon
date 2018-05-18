#ifndef CARBON_IO_MEMORY_HPP
#define CARBON_IO_MEMORY_HPP

#include "io_tag.hpp"
#include "../detail/config.hpp"

#include <memory> // addressof
#include <cstring> // memcpy
#include <exception> // out_of_range

namespace carbon::io {

    class memory_input {
        const char* _buffer;
        const char* _buffer_end;

#ifdef CARBON_IO_TRACK_BYTES_COPIED
        const char* _orig_buffer;
#endif

    public:
        using io_tag = input_io_tag;

        constexpr memory_input(const void* buffer, std::size_t size) noexcept
            : _buffer(static_cast<const char*>(buffer))
            , _buffer_end(_buffer + size)
#ifdef CARBON_IO_TRACK_BYTES_COPIED
            , _orig_buffer(_buffer)
#endif
        {}

        constexpr memory_input(const void* buffer, const void* buffer_end) noexcept
            : _buffer(static_cast<const char*>(buffer))
            , _buffer_end(static_cast<const char*>(buffer_end))
#ifdef CARBON_IO_TRACK_BYTES_COPIED
            , _orig_buffer(_buffer)
#endif
        {}

        template<class T>
        void copy(T& value)
        {
            copy(value, sizeof(T));
        }

        template<class T>
        void copy(T& value, std::size_t size)
        {
            const auto temp = _buffer + size;
            if(temp >= _buffer_end)
                CARBON_IO_MEMORY_OUT_OF_RANGE(
                    "carbon::io::memory_input::copy buffer out of range");

            std::memcpy(::std::addressof(value), _buffer, size);
            _buffer = temp;
        }

#ifdef CARBON_IO_TRACK_BYTES_COPIED
        std::size_t copied() const noexcept { return _orig_buffer - _buffer; }
#endif
    };

    class memory_output {
        char*       _buffer;
        const char* _buffer_end;

#ifdef CARBON_IO_TRACK_BYTES_COPIED
        const char* _orig_buffer;
#endif

    public:
        using io_tag = output_io_tag;

        constexpr memory_output(void* buffer, std::size_t size) noexcept
            : _buffer(static_cast<char*>(buffer))
            , _buffer_end(_buffer + size)
#ifdef CARBON_IO_TRACK_BYTES_COPIED
            , _orig_buffer(_buffer)
#endif
        {}

        constexpr memory_output(void* buffer, const void* buffer_end) noexcept
            : _buffer(static_cast<char*>(buffer))
            , _buffer_end(static_cast<const char*>(buffer_end))
#ifdef CARBON_IO_TRACK_BYTES_COPIED
            , _orig_buffer(_buffer)
#endif
        {}

        template<class T>
        void copy(const T& value)
        {
            copy(value, sizeof(T));
        }

        template<class T>
        void copy(const T& value, std::size_t size)
        {
            const auto temp = _buffer + size;
            if(temp >= _buffer_end)
                CARBON_IO_MEMORY_OUT_OF_RANGE(
                    "carbon::io::memory_output::copy buffer out of range");

            std::memcpy(_buffer, ::std::addressof(value), size);
            _buffer = temp;
        }

#ifdef CARBON_IO_TRACK_BYTES_COPIED
        std::size_t copied() const noexcept { return _orig_buffer - _buffer; }
#endif
    };

    struct memory {
        using input  = memory_input;
        using output = memory_output;
    };

} // namespace carbon::io

#endif
