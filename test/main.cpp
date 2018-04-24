#include "../include/carbon/unchecked_memory_archive.hpp"
#include "../include/carbon.hpp"
#include <iostream>
#include <fstream>
#include <deque>

struct bar {
    int                  i;
    float                f;
    std::tuple<int, int> t;
};

struct foo {
    bar               b;
    std::vector<char> s;
    std::array<char, 12> arr;
    double            d;
};

int main()
{
    char          buffer[0x1000];
    foo           f;
    std::ifstream in("test.txt", std::ios::binary);
    if (in.is_open()) {
        std::copy(std::istream_iterator<char>(in), {}, buffer);
        carbon::input_archive::unchecked_memory archive(buffer);
        archive(f);

        std::cout << f.b.i << f.b.f << f.s[0] << f.s[1] << f.s[2] << f.d;
        in.close();
    }

    f = foo{ { 2, 6.f }, { 'b', 'c', 'd' }, 2 };
    carbon::output_archive::unchecked_memory archive(buffer);
    archive(f);

    std::ofstream out("test.txt", std::ios::binary);
    std::copy(buffer, buffer + archive.copied(), std::ostream_iterator<char>(out));
}
