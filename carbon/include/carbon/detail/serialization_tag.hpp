#pragma once
#include "meta.hpp"

namespace carbon { namespace detail {

    struct specialized_tag {};
    struct fundamental_tag {};
    struct iterable_tag {};
    struct tuple_tag {};

    // I know it's ugly, okay
    template<class T>
    using serialization_tag = std::conditional_t<
        std::is_fundamental<T>::value,
        fundamental_tag,
        std::conditional_t<
            is_serializer_specialized<T>::value,
            specialized_tag,
            std::conditional_t<is_iterable<T>::value,
                               iterable_tag,
                               std::conditional_t<is_tuple_like<T>::value, tuple_tag, void>>>>;

}} // namespace carbon::detail
