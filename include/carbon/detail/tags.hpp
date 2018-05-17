#ifndef CARBON_DETAIL_TAGS_HPP
#define CARBON_DETAIL_TAGS_HPP

#include "traits.hpp"

namespace carbon { namespace detail {

    /// \brief Contains all serialization tag types
    namespace tag {

        struct continguos_iterable {};
        struct trivially_copyable {};
        struct specialized {};
        struct iterable {};
        struct array {};
        struct tuple {};
        struct none {};

    } // namespace tag

    /// \brief returns the serialization tag for type T
    template<class T>
    inline constexpr auto serialization_tag() noexcept
    {
        if constexpr (traits::has_carbon_type<T>::value)
            return tag::specialized();
        if constexpr (traits::is_iterable<T>::value) {
            if constexpr (traits::is_array<T>::value)
                return tag::array();
            if constexpr (traits::is_continguous<T>::value)
                return tag::continguos_iterable();
            else
                return tag::iterable();
        }
        else if constexpr (std::is_trivially_copyable_v<T>)
            return tag::trivially_copyable();
        else if constexpr (traits::is_tuple_like<T>::value)
            return tag::tuple();
        else
            return tag::none();
    }

    /// \brief the serialization tag type of T
    template<class T>
    using serialization_tag_t = std::decay_t<decltype(serialization_tag<T>())>;

}} // namespace carbon::detail

#endif // !CARBON_DETAIL_TAGS_HPP
