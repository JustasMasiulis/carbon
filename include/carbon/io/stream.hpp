#ifndef CARBON_IO_STREAM_HPP
#define CARBON_IO_STREAM_HPP

#include <istream>
#include <ostream>

// TODO std::addressof and helper function

namespace carbon::io {

    class stream_input {
        std::istream& _stream;

    public:
        constexpr static bool is_input_archive = true;
        using io_reference                     = stream_input;

        stream_input(std::istream& is) noexcept : _stream(is) {}

        template<class T>
        void copy(T& value)
        {
            _stream.read(reinterpret_cast<char*>(&value), sizeof(value));
        }

        template<class T>
        void copy(T& value, std::size_t size)
        {
            _stream.read(reinterpret_cast<char*>(&value), size);
        }
    };

    class stream_output {
        std::ostream& _stream;

    public:
        constexpr static bool is_input_archive = false;
        using io_reference                     = stream_output;

        stream_output(std::ostream& os) noexcept : _stream(os) {}

        template<class T>
        void copy(const T& value)
        {
            _stream.write(reinterpret_cast<const char*>(&value), sizeof(value));
        }

        template<class T>
        void copy(const T& value, std::size_t size)
        {
            _stream.write(reinterpret_cast<const char*>(&value), size);
        }
    };

    struct stream {
        using input  = stream_input;
        using output = stream_output;
    };

} // namespace carbon::io

#endif
