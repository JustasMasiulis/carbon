/*
 * Copyright 2018 Justas Masiulis
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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

        template<class Archive, class M>
        inline void
        serialize_one(typename M::class_type& value, Archive& ar, std::true_type)
        {
            ar.template begin_object<typename M::value_type, typename M::name>();
            M::value_type::serializer_type::serialize(value.*M::pointer, ar);
            ar.template end_object<typename M::value_type, typename M::name>();
        }

        template<class Archive, class M>
        inline void
        serialize_one(typename M::class_type& value, Archive& ar, std::false_type)
        {
            ar.copy<typename M::value_type, typename M::name>(value.*M::pointer);
        }

        template<class Archive, class M, class M2, class... Rest>
        static void serialize_members(typename M::class_type& target, Archive& ar)
        {
            serialize_members<Archive, M>(target, ar);
            serialize_members<Archive, M2, Rest...>(target, ar);
        }

        template<class Archive, class M>
        static void serialize_members(typename M::class_type& value, Archive& ar)
        {
            serialize_one<Archive, M>(
                value, ar, is_serializer_specialized<typename M::value_type>());
        }

    } // namespace detail

    template<class T, T P>
    struct m_ {
        using value_type = detail::member_value_t<T>;
        using class_type = detail::member_class_t<T>;
        using name       = void;

        constexpr static T pointer = P;
    };

    template<class Name, class T, T P>
    struct named_ {
        using value_type           = detail::member_value_t<T>;
        using class_type           = detail::member_class_t<T>;
        constexpr static T pointer = P;
        using name                 = Name;
    };

} // namespace carbon
