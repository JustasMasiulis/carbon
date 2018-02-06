#include "../include/carbon.hpp"
#include <fstream>
#include <vector>
#include <list>
#include <tuple>
#include <array>
#include "../include/carbon/archives/json.hpp"

struct baz {
    std::vector<int> v;
    std::size_t      s;
    CARBON_NAMED_SERIALIZABLE(baz, v, s);
};

struct test {
    int   a;
    float b;
    CARBON_NAMED_SERIALIZABLE(test, a, b);
};

struct triv_copyable {
    int    i;
    float  floateroo;
    double d;
    test   testerroo;

    CARBON_NAMED_SERIALIZABLE(triv_copyable, i, floateroo, d, testerroo);
};

struct foo {
    triv_copyable          tc;
    int                    i;
    std::tuple<int, float> t;
    std::list<baz>         b;
    std::array<int, 5>     a;
    CARBON_NAMED_SERIALIZABLE(foo, tc, i, a);
};

int main()
{
    foo f;
    f.i    = 2;
    f.t    = std::make_tuple(2, 3.f);
    f.b    = { { { 1, 2, 3 }, 4 }, { { 4, 5, 6, 7 }, 5 }, { { 8, 9 }, 10 } };
    f.a[0] = 1;
    f.a[1] = 2;

    triv_copyable tc;
    /*tc.d   = 1;
    tc.floateroo   = 2;
    tc.i   = 5;
    tc.testerroo.a = 6;
    tc.testerroo.b = 1233;*/
    std::ifstream in("testj.txt", std::ios::binary);

    if (in.is_open()) {
        carbon::deserialize<carbon::archive::json_input>(tc, in);
        in.close();
    }
    std::ofstream out("testj.txt", std::ios::binary);
    carbon::serialize<carbon::archive::json_output>(tc, out);
}
