#ifndef CARBON_VISIT_MEMBERS_HPP
#define CARBON_VISIT_MEMBERS_HPP

#include "traits.hpp"
#include <tuple>

namespace carbon { namespace detail {

    template<class T, class V>
    struct constant_ {
        constexpr static T value = V;
    };

    template<class T, class Archive, class Callback, class... Mptrs>
    void _visit_members_unpacked(T& this_, Archive& archive, Callback cb)
    {}


    template<class T, class Archive, class Callback, std::size_t... Is>
    void _visit_members_indexed(T&       this_,
                                Archive& archive,
                                Callback cb,
                                std::index_sequence<Is...>)
    {
        _visit_members_unpacked<
            T,
            Archive,
            Callback,
            constant_<std::tuple_element_t<Is, T::carbon_members>,
                      std::get<Is>(T::carbon_members)>...>(this_, archive, cb);
    }


    template<class T, class Archive, class Callback>
    void visit_members(T& this_, Archive& archive, Callback cb)
    {
        if constexpr (traits::has_carbon_type<T>::value)
            _visit_members(this_,
                           archive,
                           cb,
                           std::make_index_sequence<
                               std::tuple_size<T::carbon_members>::value>());
        else
            archive.copy(this_);
    }
}} // namespace carbon::detail

#endif // !CARBON_VISIT_MEMBERS_HPP
