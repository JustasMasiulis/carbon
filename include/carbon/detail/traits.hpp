#ifndef CARBON_DETAIL_TRAITS_HPP
#define CARBON_DETAIL_TRAITS_HPP

#include <type_traits>

namespace carbon { namespace traits {

    namespace detail {

        /// \brief void_t was only introduced in c++17 although it
        /// should work even on c++14
        template<class...>
        using void_t = void;

    } // namespace detail

    /// \brief std::true_type if a type has carbon_type member
    /// false if not
    /// @{
    template<class, class = detail::void_t<>>
    struct has_carbon_type : std::false_type {};

    template<class T>
    struct has_carbon_type<T,
                           std::void_t<typename T::template carbon_type<void, void>>>
        : std::true_type {};
    /// @}

}} // namespace carbon::traits

#endif // !CARBON_DETAIL_TRAITS_HPP
