#ifndef CARBON_VISIT_MEMBERS_HPP
#define CARBON_VISIT_MEMBERS_HPP

#include "generated_type_to_tuple.hpp"
#include "tags.hpp"
#include "copy_dispatch.hpp"

namespace carbon { namespace detail {

    template<class T, class Archive, std::size_t N, std::size_t I = 0>
    struct members_visitor_t {
        static void visit(T& this_ref, Archive& archive)
        {
            constexpr auto mptr = std::get<I>(T::template carbon_type<T>::target_members);
            visit_members(this_ref.*mptr);
            members_visitor_t<T, Archive, N, I + 1>::visit(this_ref, archive);
        }
    };

    template<class T, class Archive, std::size_t N>
    struct members_visitor_t<T, Archive, N, N> {
        constexpr static void visit(T&, Archive&) noexcept {}
    };

    template<class T, class Archive, std::size_t N, std::size_t I = 0>
    struct magic_members_visitor_t {
        static void visit(T& this_ref, Archive& archive)
        {
            auto& member_ref = boost::pfr::detail::sequence_tuple::get<I>(
                boost::pfr::detail::tie_as_tuple(this_ref));
            visit_members(member_ref, archive);

            magic_members_visitor_t<T, Archive, N, I + 1>::visit(this_ref, archive);
        }
    };

    template<class T, class Archive, std::size_t N>
    struct magic_members_visitor_t<T, Archive, N, N> {
        constexpr static void visit(T&, Archive&) noexcept {}
    };

    template<class T, class Archive>
    inline void visit_members(T& value, Archive& archive)
    {
        constexpr auto tag = serialization_tag<T>();
        copy_dispatch(value, archive, tag);
    }
}} // namespace carbon::detail

#endif // !CARBON_VISIT_MEMBERS_HPP
