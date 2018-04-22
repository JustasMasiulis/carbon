#ifndef CARBON_STREAM_ARCHIVE_HPP
#define CARBON_STREAM_ARCHIVE_HPP
#include <cstdlib>
#include <exception>

namespace carbon {

    namespace input_archive {

        class memory {
            const char* _buffer;
            const char* _buffer_end;

        public:
            constexpr static bool is_input_archive = true;

            constexpr memory(const void* buffer, std::size_t size) noexcept
                : _buffer(static_cast<const char*>(buffer)), _buffer_end(_buffer + size)
            {}

            constexpr memory(const void* buffer, const void* buffer_end) noexcept
                : _buffer(static_cast<const char*>(buffer))
                , _buffer_end(static_cast<const char*>(buffer_end))
            {}

            template<class T>
            void copy(T& value)
            {
                const auto temp = _buffer + sizeof(T);
                if (temp >= _buffer_end)
                    throw std::out_of_range(
                        "carbon::input_archive::memory::copy(T) buffer too small");

                std::memcpy(::std::addressof(value), _buffer, sizeof(T));
                _buffer = temp;
            }

            template<class T>
            void copy(T& value, std::size_t size)
            {
                const auto temp = _buffer + size;
                if (temp >= _buffer_end)
                    throw std::out_of_range(
                        "carbon::input_archive::memory::copy(T, size_t) buffer too small");

                std::memcpy(::std::addressof(value), _buffer, sizeof(T));
                _buffer = temp;
            }
        };

    } // namespace input_archive

    namespace output_archive {

        class memory {
            const char* _buffer;
            const char* _buffer_end;

        public:
            constexpr static bool is_input_archive = true;

            constexpr memory(const void* buffer, std::size_t size) noexcept
                : _buffer(static_cast<const char*>(buffer)), _buffer_end(_buffer + size)
            {}

            constexpr memory(const void* buffer, const void* buffer_end) noexcept
                : _buffer(static_cast<const char*>(buffer))
                , _buffer_end(static_cast<const char*>(buffer_end))
            {}

            template<class T>
            void copy(const T& value)
            {
                const auto temp = _buffer + sizeof(T);
                if (temp >= _buffer_end)
                    throw std::out_of_range(
                        "carbon::input_archive::memory::copy(T) buffer too small");

                std::memcpy(_buffer, ::std::addressof(value), sizeof(T));
                _buffer = temp;
            }

            template<class T>
            void copy(const T& value, std::size_t size)
            {
                const auto temp = _buffer + size;
                if (temp >= _buffer_end)
                    throw std::out_of_range(
                        "carbon::input_archive::memory::copy(T, size_t) buffer too small");

                std::memcpy(_buffer, ::std::addressof(value), sizeof(T));
                _buffer = temp;
            }
        };

    } // namespace output_archive

} // namespace carbon

#endif
