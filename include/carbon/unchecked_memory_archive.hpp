#ifndef CARBON_UNCHECKED_MEMORY_ARCHIVE_HPP
#define CARBON_UNCHECKED_MEMORY_ARCHIVE_HPP

#include "archive_base.hpp"

namespace carbon {

    namespace input_archive {

        class unchecked_memory : public archive_base<unchecked_memory> {
            const char* _buffer;
            std::size_t _copied = 0;

        public:
            constexpr static bool is_input_archive = true;

            constexpr unchecked_memory(const void* buffer) noexcept
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
                _copied += size;
            }

            std::size_t copied() const noexcept { return _copied; }
        };

    } // namespace input_archive

    namespace output_archive {

        class unchecked_memory : public archive_base<unchecked_memory> {
            char*       _buffer;
            std::size_t _copied = 0;

        public:
            constexpr static bool is_input_archive = false;

            constexpr unchecked_memory(void* buffer) noexcept
                : _buffer(static_cast<char*>(buffer))
            {}

            template<class T>
            void copy(const T& value) noexcept
            {
                std::memcpy(_buffer, ::std::addressof(value), sizeof(T));
                _buffer += sizeof(T);
                _copied += sizeof(T);
            }

            template<class T>
            void copy(const T& value, std::size_t size) noexcept
            {
                std::memcpy(_buffer, ::std::addressof(value), size);
                _buffer += size;
                _copied += size;
            }

            std::size_t copied() const noexcept { return _copied; }
        };

    } // namespace output_archive

} // namespace carbon

#endif
