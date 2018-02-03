#pragma once
#include <type_traits>

namespace carbon { namespace proxy {

    struct input_proxy_tag {};
    struct output_proxy_tag {};

    struct single_level_proxy_tag {};
    struct multi_level_proxy_tag {};

    template<class P>
    struct is_input : std::is_same<typename P::proxy_category, proxy::input_proxy_tag> {};

    template<class P>
    struct is_output : std::is_same<typename P::proxy_category, proxy::output_proxy_tag> {};


    template<class P>
    struct is_single_level : std::is_same<typename P::proxy_structure, single_level_proxy_tag> {};

    template<class P>
    struct is_multi_level : std::is_same<typename P::proxy_structure, multi_level_proxy_tag> {};

}} // namespace carbon::proxy
