#pragma once

namespace carbon { namespace detail {

    template<std::size_t I, class T, class... Args>
    struct _nth_type {
        using type = _nth_type<I - 1, T>;
    };

    template<class T, class... Args>
    struct _nth_type<0, T, Args...> {
        using type = T;
    };

    /// /brief wraps a single constant value
    template<class T, T P>
    struct constant_ {
        constexpr static T value = P;
    };

    /// /brief Wraps a list of member pointers
    template<class... Ptrs>
    struct members_list {
        /// \brief Number of member pointers stored
        constexpr static std::size_t size = sizeof...(Ptrs);

        /// \brief Returns the member pointer at given index
        template<std::size_t I>
        constexpr static auto get()
        {
            return _nth_type<I, Ptrs...>::value;
        }
    };

    /// \brief Creates a new members list by deducing parameter types
    template<class... Args>
    inline constexpr auto make_members_list( Args&&... member_pointers)
    {
        return members_list<constant_<Args, member_pointers>...>();
    }

}} // namespace carbon::detail
