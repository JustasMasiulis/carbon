#ifndef CARBON_STREAM_ARCHIVE_HPP
#define CARBON_STREAM_ARCHIVE_HPP
#include <istream>
#include <ostream>

namespace carbon {

    namespace input_archive {

        class stream {
            std::istream& _stream;

        public:
            constexpr static bool is_input_archive = true;

            stream(std::istream& is) noexcept : _stream(is) {}

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

    } // namespace input_archive

    namespace output_archive {

        class stream {
            std::ostream& _stream;

        public:
            constexpr static bool is_input_archive = false;

            stream(std::ostream& os) noexcept : _stream(os) {}

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

    } // namespace output_archive

} // namespace carbon

#endif
