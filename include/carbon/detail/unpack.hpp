#ifndef CARBON_DETAIL_UNPACK_HPP
#define CARBON_DETAIL_UNPACK_HPP

#include "traits.hpp"

namespace carbon { namespace detail {

    template<class T, class Archive, class... Args>
    inline T unpack(Archive& archive, Args&&... args)
    {
        if constexpr (traits::has_carbon_type<T>::value) {
            using carbon_type = typename T::template carbon_type<T, Archive>;
            if constexpr (std::is_constructible<T, carbon_type, Args...>::value)
                return T(carbon_type(archive),
                         std::forward<T>(args)); // carbon::construct
            else {
                static_assert(
                    std::is_default_constructible<T>::value,
                    "non default constructible without carbon_type constructor");

                T value;
                archive.copy(value)
            }
        }
    }

}} // namespace carbon::detail

#endif // !CARBON_DETAIL_UNPACK_HPP
