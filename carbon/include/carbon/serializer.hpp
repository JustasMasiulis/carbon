#pragma once
#include "members.hpp"

namespace carbon {

    template<class... Ms>
    struct serializer {
        template<class T, class Proxy>
        static void serialize(T& this_, Proxy proxy)
        {
            detail::serialize_members<Proxy, Ms...>(this_, proxy);
        }
    };

} // namespace carbon
