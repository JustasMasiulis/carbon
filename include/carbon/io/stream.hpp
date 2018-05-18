#ifndef CARBON_IO_STREAM_HPP
#define CARBON_IO_STREAM_HPP

#include "io_tag.hpp"
#include "../detail/config.hpp"

#include <memory>
#include <istream>
#include <ostream>

namespace carbon::io {

    class stream_input {
        std::istream& _stream;

#ifdef CARBON_IO_TRACK_BYTES_COPIED
        std::size_t _bytes_copied = 0;
#endif

    public:
        using io_tag       = input_io_tag;

        stream_input(std::istream& is) noexcept : _stream(is) {}

        template<class T>
        void copy(T& value)
        {
            copy(value, sizeof(value));
        }

        template<class T>
        void copy(T& value, std::size_t size)
        {
            _stream.read(reinterpret_cast<char*>(::std::addressof(value)), size);
#ifdef CARBON_IO_TRACK_BYTES_COPIED
            _bytes_copied += size;
#endif
        }

#ifdef CARBON_IO_TRACK_BYTES_COPIED
        std::size_t copied() const noexcept { return _bytes_copied; }
#endif
    };

    class stream_output {
        std::ostream& _stream;

#ifdef CARBON_IO_TRACK_BYTES_COPIED
        std::size_t _bytes_copied = 0;
#endif

    public:
        using io_tag       = output_io_tag;

        stream_output(std::ostream& os) noexcept : _stream(os) {}

        template<class T>
        void copy(const T& value)
        {
            copy(value, sizeof(value));
        }

        template<class T>
        void copy(const T& value, std::size_t size)
        {
            _stream.write(reinterpret_cast<const char*>(::std::addressof(value)), size);

#ifdef CARBON_IO_TRACK_BYTES_COPIED
            _bytes_copied += size;
#endif
        }

#ifdef CARBON_IO_TRACK_BYTES_COPIED
        std::size_t copied() const noexcept { return _bytes_copied; }
#endif
    };

    struct stream {
        using input  = stream_input;
        using output = stream_output;
    };

} // namespace carbon::io

#endif
