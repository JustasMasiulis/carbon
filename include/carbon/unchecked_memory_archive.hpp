#ifndef CARBON_UNCHECKED_MEMORY_ARCHIVE_HPP
#define CARBON_UNCHECKED_MEMORY_ARCHIVE_HPP
#include <cstdlib>

namespace carbon {

    namespace input_archive {

        class unchecked_memory {
            const char* _buffer;

        public:
            constexpr static bool is_input_archive = true;

            constexpr unchecked_memory(const void* buffer) noexcept
                : _buffer(static_cast<const char*>(buffer))
            {}

            template<class T>
            void copy(T& value) noexcept
            {
                std::memcpy(::std::addressof(value), _buffer, sizeof(T));
                _buffer += sizeof(T);
            }

            template<class T>
            void copy(T& value, std::size_t size) noexcept
            {
                std::memcpy(::std::addressof(value), _buffer, size);
                _buffer += size;
            }
        };

    } // namespace input_archive

    namespace output_archive {

        class unchecked_memory {
            char* _buffer;

        public:
            constexpr static bool is_input_archive = true;

            constexpr unchecked_memory(void* buffer) noexcept
                : _buffer(static_cast<char*>(buffer))
            {}

            template<class T>
            void copy(const T& value) noexcept
            {
                std::memcpy(_buffer, ::std::addressof(value), sizeof(T));
                _buffer += sizeof(T);
            }

            template<class T>
            void copy(const T& value, std::size_t size) noexcept
            {
                std::memcpy(_buffer, ::std::addressof(value), size);
                _buffer += size;
            }
        };

    } // namespace output_archive

} // namespace carbon

#endif
