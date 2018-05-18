#ifndef CARBON_SAVE_SIZE_HPP
#define CARBON_SAVE_SIZE_HPP

#include "config.hpp"

#ifndef CARBON_NO_CONTAINER_SIZE_CHECK
#include <stdexcept>
#include <limits>
#endif

#include <iterator>

namespace carbon::detail {

    template<class T, class Io>
    inline CARBON_CONTAINER_SIZE_TYPE save_size(const T& value, Io& io)
    {
        // get the size
        using std::size;
        const auto unchecked_size = size(value);

        // if size check is enabled
#ifndef CARBON_NO_CONTAINER_SIZE_CHECK

        // check if there is a possibility of overflow at all first
        if constexpr(sizeof(unchecked_size) > sizeof(CARBON_CONTAINER_SIZE_TYPE)) {
            if(unchecked_size > std::numeric_limits<CARBON_CONTAINER_SIZE_TYPE>::max())
                CARBON_CONTAINER_SIZE_OVERFLOW; // throws std::length_error by default
        }

#endif

        const auto checked = static_cast<CARBON_CONTAINER_SIZE_TYPE>(unchecked_size);
        io.copy(checked);
        return checked;
    }

} // namespace carbon::detail

#endif