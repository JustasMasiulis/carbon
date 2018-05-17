#ifndef CARBON_VISIT_MEMBERS_HPP
#define CARBON_VISIT_MEMBERS_HPP

#include "tags.hpp"
#include "generated_type_to_tuple.hpp"
#include "copy_dispatch.hpp"

namespace carbon { namespace detail {

    struct members_visitor_t {
        template<std::size_t I, class T, class Archive>
        static void visit(T& this_ref, Archive& archive)
        {
            constexpr auto mptr = std::get<I>(T::template carbon_type<T>::target_members);
            copy_dispatch(this_ref.*mptr, archive);
        }
    };

    struct magic_members_visitor_t {
        template<std::size_t I, class T, class Archive>
        static void visit(T& value, Archive& archive)
        {
            auto& mref = pfr::get<I>(pfr::tie_as_tuple(value));
            copy_dispatch(mref, archive);
        }
    };

    template<class T, class Archive, class Visitor, std::size_t N, std::size_t I = 0>
    struct members_for_each {
        static void visit(T& value, Archive& archive)
        {
            Visitor::template visit<I>(value, archive);
            members_for_each<T, Archive, Visitor, N, I + 1>::visit(value, archive);
        }
    };

    template<class T, class Archive, class Visitor, std::size_t N>
    struct members_for_each<T, Archive, Visitor, N, N> {
        constexpr static void visit(T&, Archive&) noexcept {}
    };

}} // namespace carbon::detail

#endif // !CARBON_VISIT_MEMBERS_HPP
