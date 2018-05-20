#define CARBON_IO_TRACK_BYTES_COPIED
#include "../include/carbon/io/unchecked_memory.hpp"
#include "../include/carbon/format/binary.hpp"
#include "../include/carbon.hpp"
#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <istream>
#include "../include/carbon/format/json.hpp"
template<auto Ptr, std::size_t N>
struct nv {
    const char*           name;
    constexpr static auto len = N;
    constexpr static auto ptr = Ptr;
};

struct bar {
    int                  i;
    float                f;
    std::tuple<int, int> t;
};

struct foo {
    bar               b;
    std::vector<char> s;
    double            d;

    template<class T>
    struct carbon_type {
        //constexpr static auto members = carbon::detail::pfr::make_tuple(nv<&T::b, 2>{ "b" },
        //                                                                nv<&T::s, 2>{ "S" },
        //                                                                nv<&T::d, 2>{ "d" });
        constexpr static auto members =
            carbon::detail::pfr::make_tuple(&T::b, &T::s, &T::d);
		
        constexpr static bool named   = false;
    };
};

int main()
{
    using serializer =
        carbon::serializer_t<carbon::format::binary, carbon::io::unchecked_memory>;

    char          buffer[0x1000];
    foo           f;
    std::ifstream in("test.txt", std::ios::binary);
    if(in.is_open()) {
        std::copy(std::istream_iterator<char>(in), {}, buffer);
        carbon::load<serializer>(f, buffer);

        std::cout << f.b.i << f.b.f << f.s[0] << f.s[1] << f.s[2] << f.d;
        in.close();
    }

	std::ofstream out("test.json");
    f           = foo{ { 2, 6.f }, { 'b', 'c', 'd' }, { 2.0 } };
    carbon::save<carbon::format::json, carbon::io::stream>(f, out);

    //std::ofstream out("test.json", std::ios::binary);
    //std::copy(buffer, buffer + format.io().copied(), std::ostream_iterator<char>(out));
}
