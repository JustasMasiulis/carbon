#ifndef CARBON_VISIT_MEMBERS_HPP
#define CARBON_VISIT_MEMBERS_HPP

#include "tags.hpp"
#include "generated_type_to_tuple.hpp"

namespace carbon::detail {

    template<class T>
    inline constexpr std::size_t num_members(tag::specialized) noexcept
    {
        using ctype = typename T::template carbon_type<T>;
        return ctype{}.members.size_v;
    }

    template<class T>
    inline constexpr std::size_t num_members(tag::none) noexcept
    {
        return detail::pfr::fields_count<T>();
    }

    struct members_visitor_t {
        template<std::size_t I, class T, class Callback>
        static void visit(T& this_ref, Callback& callback)
        {
            using ctype           = typename T::template carbon_type<T>;
            constexpr auto member = pfr::get<I>(ctype::members);
            if constexpr(ctype::named) {
                callback(this_ref.*member.ptr, std::string_view(member.name, member.len - 1));
            }
            else
                callback(this_ref.*member);
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

    template<class T,
             class Visitor,
             std::size_t N = num_members<std::decay_t<T>>(serialization_tag<T>()),
             std::size_t I = 0>
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

} // namespace carbon::detail

#endif // !CARBON_VISIT_MEMBERS_HPP
