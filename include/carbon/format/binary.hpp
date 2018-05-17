#ifndef CARBON_FORMAT_BINARY_HPP
#define CARBON_FORMAT_BINARY_HPP

#include "../detail/copy_dispatch.hpp"
#include "../io/io_tag.hpp"

namespace carbon::format {

    template<class Io>
    class binary {
        template<class T>
        using value_ref =
            typename io::detail::io_value_reference<typename Io::io_tag, T>::ref;

    public:
        using io_type = Io;

        template<class Io_>
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
            detail::members_for_each<T, detail::magic_members_visitor_t, size>::visit(
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
            if constexpr(std::is_same_v<serialization_tag_t<value_type>,
                                        tag::trivially_copyable>)
                _io.copy(*std::begin(value), sizeof(T));
            else {
                auto       first = std::begin(value);
                const auto last  = std::end(value);
                for(; first != last; ++first)
                    copy_dispatch(*first);
            }
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>& value, detail::tag::continguos_iterable)
        {
            // continguos_iterable is only string and vector - no need for ADL stuff
            std::uint32_t size;
            if constexpr(std::is_same_v<typename io_type::io_tag, io::input_io_tag>) {
                _io.copy(size);
                value.resize(size);
            }
            else {
                size = static_cast<std::uint32_t>(value.size());
                _io.copy(size);
            }

            if constexpr(std::is_same_v<
                             detail::serialization_tag_t<typename T::value_type>,
                             detail::tag::trivially_copyable>)
                _io.copy(value.front(), size * sizeof(typename T::value_type));
            else {
                auto       first = value.begin();
                const auto last  = value.end();

                for(; first != last; ++first)
                    copy_dispatch(*first);
            }
        }

        template<class T>
        inline void copy_dispatch(value_ref<T>& value, detail::tag::iterable)
        {
            using std::begin;
            using std::end;
            using std::size;

            if constexpr(std::is_same_v<typename io_type::io_tag, io::input_io_tag>) {
                std::uint32_t size;
                _io.copy(size);

                while(size--) {
                    if constexpr(traits::has_emplace_back<T>::value)
                        copy_dispatch(value.emplace_back());
                    else // TODO save the iterator
                        copy_dispatch(*value.emplace(end(value)));
                }
            }
            else {
                auto       first = begin(value);
                const auto last  = end(value);
                _io.copy(static_cast<std::uint32_t>(size(value)));
                for(; first != last; ++first)
                    copy_dispatch(*first);
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
