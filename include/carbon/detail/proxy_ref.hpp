#pragma once

namespace carbon { namespace detail {

    template<class T, class TF>
    struct _proxy_ref;

    template<class T>
    struct _proxy_ref<T, std::false_type> /* input proxy */ {
        using type = T&;
    };

    template<class T>
    struct _proxy_ref<T, std::true_type> /* output proxy */ {
        using type = const T&;
    };

    //template<class T, class Proxy>
    //using proxy_ref_ = typename _proxy_ref<T, proxy::is_output<Proxy>>::type;

}} // namespace carbon::detail
