#pragma once
#include "detail/copy_one.hpp"

namespace carbon {

    namespace detail {

        template<class>
        struct member_traits;

        template<class R, class T>
        struct member_traits<R T::*> {
            using value_type = R;
            using class_type = T;
        };

        template<class T>
        using member_class_t = typename member_traits<T>::class_type;

        template<class T>
        using member_value_t = typename member_traits<T>::value_type;

        template<class Proxy, class M, class M2, class... Rest>
        static void serialize_members(typename M::class_type& target, Proxy proxy)
        {
            serialize_members<Proxy, M>(target, proxy);
            serialize_members<Proxy, M2, Rest...>(target, proxy);
        }

        template<class Proxy, class M>
        static void serialize_members(typename M::class_type& value, Proxy proxy)
        {
            copy_one(value.*M::pointer, proxy);
        }

    }

    template<class T, detail::member_value_t<T> detail::member_class_t<T>::*P>
    struct m_ {
        using value_type = detail::member_value_t<T>;
        using class_type = detail::member_class_t<T>;

        constexpr static value_type class_type::*pointer = P;
    };

} // namespace carbon
