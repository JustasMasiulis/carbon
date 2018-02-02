#pragma once
#include <type_traits>
#include <iterator>

namespace carbon { namespace detail {

    template<typename T, typename = void>
    struct is_iterable : std::false_type {};

    template<typename T>
    struct is_iterable<T,
                       std::void_t<decltype(std::declval<T>().begin()),
                                   decltype(std::declval<T>().end())>>
        : std::true_type {};

    template<typename T, typename = void>
    struct is_serializer_specialized : std::false_type {};

    template<typename T>
    struct is_serializer_specialized<T, std::void_t<typename T::serializer_type>>
        : std::true_type {};

    template<typename T, typename = void>
    struct is_tuple_like : std::false_type {};

    template<typename T>
    struct is_tuple_like<T, std::void_t<decltype(std::tuple_size<T>::value)>>
        : std::true_type {};

    struct input_proxy_tag {};
    struct output_proxy_tag {};

    template<class P>
    struct is_input_proxy : std::is_same<typename P::proxy_tag, input_proxy_tag> {};

    template<class P>
    struct is_output_proxy : std::is_same<typename P::proxy_tag, output_proxy_tag> {
    };

}} // namespace carbon::detail
