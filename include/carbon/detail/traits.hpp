#ifndef CARBON_DETAIL_TRAITS_HPP
#define CARBON_DETAIL_TRAITS_HPP

#include <type_traits>
#include <cstdint>

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
    struct has_carbon_type<T, std::void_t<typename T::template carbon_type<void, void>>>
        : std::true_type {};
    /// @}

    template<class T, class = void>
    struct has_emplace_back : std::false_type {};
    template<class T>
    struct has_emplace_back<T, std::void_t<decltype(std::declval<T&>().emplace_back())>>
        : std::true_type {};

    template<class T, class = void>
    struct size_getter {
        static std::uint32_t get(T& value)
        {
            using std::begin;
            using std::end;
            const auto first = begin(value);
            const auto last  = end(value);
            return static_cast<std::uint32_t>(last - first);
        }
    };

    using std::size;
    template<class T>
    struct size_getter<T, std::void_t<decltype(size(std::declval<T&>()))>> {
        static std::uint32_t get(T& value)
        {
            return static_cast<std::uint32_t>(size(value));
        }
    };

}} // namespace carbon::traits

#endif // !CARBON_DETAIL_TRAITS_HPP
