#ifndef CARBON_IO_MEMORY
#define CARBON_IO_MEMORY

#include "base.hpp"
#include <exception>

namespace carbon::io {

    class memory_input {
        const char* _buffer;
        const char* _buffer_end;
        const char* _orig_buffer;

    public:
        constexpr static bool is_input_archive = true;
        using io_reference                     = memory_input&;

        constexpr memory_input(const void* buffer, std::size_t size) noexcept
            : _buffer(static_cast<const char*>(buffer))
            , _buffer_end(_buffer + size)
            , _orig_buffer(_buffer)
        {}

        constexpr memory_input(const void* buffer, const void* buffer_end) noexcept
            : _buffer(static_cast<const char*>(buffer))
            , _buffer_end(static_cast<const char*>(buffer_end))
            , _orig_buffer(_buffer)
        {}

        template<class T>
        void copy(T& value)
        {
            const auto temp = _buffer + sizeof(T);
            if(temp >= _buffer_end)
                throw std::out_of_range(
                    "carbon::input_archive::memory::copy(T) buffer too small");

            std::memcpy(::std::addressof(value), _buffer, sizeof(T));
            _buffer = temp;
        }

        template<class T>
        void copy(T& value, std::size_t size)
        {
            const auto temp = _buffer + size;
            if(temp >= _buffer_end)
                throw std::out_of_range(
                    "carbon::input_archive::memory::copy(T, size_t) buffer too small");

            std::memcpy(::std::addressof(value), _buffer, size);
            _buffer = temp;
        }

        std::size_t copied() const noexcept { return _orig_buffer - _buffer; }
    };

    class memory_output : public io_base<memory_output> {
        char*       _buffer;
        const char* _buffer_end;
        const char* _orig_buffer;

    public:
        constexpr static bool is_input_archive = false;
        using io_reference                     = memory_output&;


        constexpr memory_output(void* buffer, std::size_t size) noexcept
            : _buffer(static_cast<char*>(buffer))
            , _buffer_end(_buffer + size)
            , _orig_buffer(_buffer)
        {}

        constexpr memory_output(void* buffer, const void* buffer_end) noexcept
            : _buffer(static_cast<char*>(buffer))
            , _buffer_end(static_cast<const char*>(buffer_end))
            , _orig_buffer(_buffer)
        {}

        template<class T>
        void copy(const T& value)
        {
            const auto temp = _buffer + sizeof(T);
            if(temp >= _buffer_end)
                throw std::out_of_range(
                    "carbon::input_archive::memory::copy(T) buffer too small");

            std::memcpy(_buffer, ::std::addressof(value), sizeof(T));
            _buffer = temp;
        }

        template<class T>
        void copy(const T& value, std::size_t size)
        {
            const auto temp = _buffer + size;
            if(temp >= _buffer_end)
                throw std::out_of_range(
                    "carbon::input_archive::memory::copy(T, size_t) buffer too small");

            std::memcpy(_buffer, ::std::addressof(value), size);
            _buffer = temp;
        }

        std::size_t copied() const noexcept { return _orig_buffer - _buffer; }
    };

    struct memory {
        using input  = memory_input;
        using output = memory_output;
    };

} // namespace carbon::io

#endif
