#ifndef CARBON_FORMAT_BINARY_HPP
#define CARBON_FORMAT_BINARY_HPP

#include "../detail/copy_dispatch.hpp"
#include "../detail/save_size.hpp"
#include "../io/io_tag.hpp"

namespace carbon::format {

    template<class Io>
    struct binary {
        using io_type = Io;

        template<class Io_,
                 std::enable_if_t<std::is_constructible_v<io_type, Io_>, int> = 0>
        binary(Io_&& io) : _io(std::forward<Io_>(io))
        {}

        template<class... Args>
        inline void operator()(Args&&... args)
        {
            (copy_dispatch<std::remove_reference_t<Args>>(args), ...);
        }

        io_type&       io() noexcept { return _io; }
        const io_type& io() const noexcept { return _io; }

    private:
        io_type _io;

        template<class T>
        using value_ref =
            typename io::detail::io_value_reference<typename Io::io_tag, T>::ref;

        template<class T>
        inline void copy_dispatch(value_ref<T>& value)
        {
            copy_dispatch<T>(value, detail::serialization_tag_t<T>{});
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>& value, detail::tag::specialized)
        {
            constexpr auto size =
                std::tuple_size<T::template carbon_type<T>::target_members>::value;
            members_for_each<T, detail::members_visitor_t, size>::visit(value, *this);
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>& value, detail::tag::none)
        {
            constexpr auto size = detail::pfr::fields_count<T>();
            detail::members_for_each<value_ref<T>&,
                                     detail::magic_members_visitor_t,
                                     size>::visit(
                value, *this);
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>& value, detail::tag::trivially_copyable)
        {
            _io.copy(value);
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>& value, detail::tag::array)
        {
            using value_type = std::remove_reference_t<decltype(value[0])>;
            if constexpr(std::is_same_v<detail::serialization_tag_t<value_type>,
                                        detail::tag::trivially_copyable>)
                _io.copy(*std::begin(value), sizeof(T));
            else
                std::for_each(std::begin(value), std::end(value), copy_dispatch);
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>& value, detail::tag::continguos_iterable)
        {
            // continguos_iterable is only string and vector - no need for ADL stuff
            CARBON_CONTAINER_SIZE_TYPE size;
            if constexpr(io::detail::is_input_io_v<io_type>) {
                // read the container size
                _io.copy(size);
                value.resize(size);
            }
            else
                size = detail::save_size(value, _io);

            // since container is continguos we can just copy the whole thing if value is
            // trivially copyable
            if constexpr(std::is_same_v<
                             detail::serialization_tag_t<typename T::value_type>,
                             detail::tag::trivially_copyable>)
                _io.copy(value.front(), size * sizeof(typename T::value_type));
            else
                std::for_each(value.begin(), value.end(), copy_dispatch);
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>& value, detail::tag::iterable)
        {
            using std::begin;
            using std::end;

            if constexpr(io::detail::is_input_io_v<io_type>) {
                CARBON_CONTAINER_SIZE_TYPE size;
                _io.copy(size);

                while(size--) {
                    if constexpr(traits::has_emplace_back<T>::value)
                        copy_dispatch(value.emplace_back());
                    else
                        copy_dispatch(*value.emplace(end(value)));
                }
            }
            else {
                detail::save_size(value, _io);
                std::for_each(begin(value), end(value), copy_dispatch);
            }
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>& value, detail::tag::tuple)
        {
            std::apply(*this, value);
        }
    };

    template<class Io>
    binary(Io &&)->binary<std::remove_reference_t<Io>>;

} // namespace carbon::format

#endif
