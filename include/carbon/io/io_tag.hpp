#ifndef CARBON_IO_TAG_HPP
#define CARBON_IO_TAG_HPP

#include <type_traits>

namespace carbon::io {

    struct input_io_tag {
    };

    struct output_io_tag {
    };

    namespace detail {

        template<class Tag, class T>
        struct io_value_reference;

        template<class T>
        struct io_value_reference<output_io_tag, T> {
            using ref = const std::remove_reference_t<T>;
        };

        template<class T>
        struct io_value_reference<input_io_tag, T> {
            using ref = std::remove_reference_t<T>;
        };

    } // namespace detail

} // namespace carbon::io

#endif
