#ifndef CARBON_DETAIL_CONFIG_HPP
#define CARBON_DETAIL_CONFIG_HPP

#ifndef CARBON_IO_MEMORY_OUT_OF_RANGE
#define CARBON_IO_MEMORY_OUT_OF_RANGE(str) throw std::out_of_range(str)
#endif

#ifndef CARBON_TYPE_NAME
#define CARBON_TYPE_NAME carbon_type
#endif

#ifndef CARBON_CONTAINER_SIZE_TYPE
#define CARBON_CONTAINER_SIZE_TYPE std::uint32_t
#endif

#ifndef CARBON_CONTAINER_SIZE_OVERFLOW
#define CARBON_CONTAINER_SIZE_OVERFLOW \
    throw std::length_error("carbon iterable container size too long")
#endif

#endif