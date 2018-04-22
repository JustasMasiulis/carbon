#ifndef CARBON_DETAIL_TRAITS_HPP
#define CARBON_DETAIL_TRAITS_HPP

// basic meta stuff
#include <type_traits>
#include <utility>

// required for detection and specializations
#include <string>
#include <vector>
#include <array>
#include <tuple>

/// \brief helper macro to create detection structs
#define CRBN_DETAIL_DETECT_T(name, ...) \
    template<class, class = void>       \
    struct name : std::false_type {};   \
                                        \
    template<class T>                   \
    struct name<T, std::void_t<__VA_ARGS__>> : std::true_type {};


namespace carbon { namespace traits {

    using std::begin;
    using std::end;

    /// \brief true_type if the type has carbon_type member false_type if not
    CRBN_DETAIL_DETECT_T(has_carbon_type, typename T::template carbon_type<T>);

    /// \brief true_type if the type has emplace_back member function false_type if not
    CRBN_DETAIL_DETECT_T(has_emplace_back, decltype(std::declval<T&>().emplace_back()));

    /// \brief true_type if begin(T&) and end(T&) are valid false_type if not
    CRBN_DETAIL_DETECT_T(is_iterable,
                         decltype(begin(std::declval<T&>())),
                         decltype(end(std::declval<T&>())));

    /// \brief true_type if std::tuple_size<T>::value is valid false_type if not
    CRBN_DETAIL_DETECT_T(is_tuple_like, decltype(std::tuple_size<T>::value));

    /// \brief true_type if T is an std::array or a C array
    /// @{
    template<class T>
    struct is_array : std::false_type {};

    template<class T, std::size_t N>
    struct is_array<std::array<T, N>> : std::true_type {};

    template<class T, std::size_t N>
    struct is_array<T[N]> : std::true_type {};
    /// @}

    /// \brief true_type if T is an std::vector or an std::string
    /// @{
    template<class T>
    struct is_continguous : std::false_type {};

    template<class T, class CharTraits, class Alloc>
    struct is_continguous<std::basic_string<T, CharTraits, Alloc>> : std::true_type {};

    template<class T, class Alloc>
    struct is_continguous<std::vector<T, Alloc>> : std::true_type {};
    /// @}

}} // namespace carbon::traits

#undef CRBN_DETAIL_DETECT_T

#endif // !CARBON_DETAIL_TRAITS_HPP
