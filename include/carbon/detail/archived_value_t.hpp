#pragma once
#include "serialization_tag.hpp"

namespace carbon { namespace util {
    namespace detail {

        template<class T, class Tag>
        struct archived_value {};

        template<class T>
        struct archived_value<T, carbon::detail::input_archive_tag> {
            using type = T&;
        };

        template<class T>
        struct archived_value<T, carbon::detail::output_archive_tag> {
            using type = const T&;
        };

    } // namespace detail

    template<class T, class Archive>
    using archived_value_t =
        typename detail::archived_value<T, typename Archive::archive_category_tag>::type;

}} // namespace carbon::util
