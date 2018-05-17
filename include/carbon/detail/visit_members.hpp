#ifndef CARBON_VISIT_MEMBERS_HPP
#define CARBON_VISIT_MEMBERS_HPP

#include "tags.hpp"
#include "generated_type_to_tuple.hpp"
#include "copy_dispatch.hpp"

namespace carbon { namespace detail {

    struct members_visitor_t {
        template<std::size_t I, class T, class Callback>
        static void visit(T& this_ref, Callback& callback)
        {
            constexpr auto mptr = std::get<I>(T::template carbon_type<T>::target_members);
            callback(this_ref.*mptr);
        }
    };

    struct magic_members_visitor_t {
        template<std::size_t I, class T, class Callback>
        static void visit(T& value, Callback& callback)
        {
            auto& mref = pfr::get<I>(pfr::tie_as_tuple(value));
            callback(mref);
        }
    };

    template<class T, class Visitor, std::size_t N, std::size_t I = 0>
    struct members_for_each {
		template<class Callback>
        static void visit(T& value, Callback& callback)
        {
            Visitor::template visit<I>(value, callback);
            members_for_each<T, Visitor, N, I + 1>::visit(value, callback);
        }
    };

    template<class T, class Visitor, std::size_t N>
    struct members_for_each<T, Visitor, N, N> {
		template<class Callback>
        constexpr static void visit(T&, Callback&) noexcept {}
    };

}} // namespace carbon::detail

#endif // !CARBON_VISIT_MEMBERS_HPP
