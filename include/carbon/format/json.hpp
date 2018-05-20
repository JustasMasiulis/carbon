#ifndef CARBON_FORMAT_JSON_HPP
#define CARBON_FORMAT_JSON_HPP

#include "../detail/visit_members.hpp"
#include "../detail/save_size.hpp"
#include "../io/io_tag.hpp"

#include "detail/json_impl.hpp"

namespace carbon::format {

    template<class Io>
    struct json : carbon::detail::format::json_base<typename Io::io_tag, json<Io>> {
        using io_type = Io;

        template<class Io_,
                 std::enable_if_t<std::is_constructible_v<io_type, Io_>, int> = 0>
        json(Io_&& io) : _io(std::forward<Io_>(io))
        {}

		json(const json&) = default;
        json(json&&)            = default;

        template<class... Args>
        inline void operator()(Args&&... args)
        {
            (base_type::copy_dispatch<std::remove_reference_t<Args>>(args), ...);
        }

        template<class U>
        inline void operator()(U&& value, std::string_view name)
        {
            base_type::copy_dispatch<std::remove_reference_t<U>>(value, name);
        }

        io_type&       io() noexcept { return _io; }
        const io_type& io() const noexcept { return _io; }

    private:
        io_type _io;
        using base_type = carbon::detail::format::json_base<typename Io::io_tag, json<Io>>;
    };

    template<class Io>
    json(Io &&)->json<std::remove_reference_t<Io>>;

} // namespace carbon::format

#endif
