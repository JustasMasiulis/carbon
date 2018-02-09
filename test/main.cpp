//#include "../include/carbon.hpp"
//#include <fstream>
//#include <vector>
//#include <list>
//#include <tuple>
//#include <array>
//#include <map>
//#include "../include/carbon/archives/json.hpp"
//
// struct baz {
//    std::vector<int> v = { 5, 6, 3, 4, 5 };
//    std::size_t      s = 2;
//    CARBON_NAMED_SERIALIZABLE(baz, v, s);
//};
//
// struct test {
//    int   a = 78;
//    float b = 79;
//    CARBON_NAMED_SERIALIZABLE(test, a, b);
//};
//
// struct triv_copyable {
//    std::map<std::string, int>                    fuckmedaddy{ {"asdasd", 6} };
//    int                                           i;
//    std::tuple<baz, std::pair<test, test>, float> tup;
//    float                                         floateroo;
//    std::array<std::array<test, 2>, 2> arr{ std::array<test, 2>{ test{ 1, 2.f },
//                                                                 test{ 2, 3.f } },
//                                            { test{ 4, 5.f }, test{ 6, 7.f } } };
//    double                             d;
//
//    CARBON_NAMED_SERIALIZABLE(triv_copyable, fuckmedaddy, i, tup, floateroo, arr,
//    d);
//};
//
#include "../include/carbon.hpp"
struct foo {
    template<class Carbon>
    foo(Carbon c, const char* test_arg)
    {}
    // triv_copyable          tc;
    int   i;
    float f;
    bool  b;
    char  c;

    CARBON_SERIALIZABLE(foo, i, f, b, c);
    // CARBON_NAMED_SERIALIZABLE(foo, tc, i, a);
};

int main()
{
    float archive;
    carbon::construct<foo>(archive, "wubadubdub");
}
//
// int main()
//{
//    foo f;
//    f.i    = 2;
//    f.t    = std::make_tuple(2, 3.f);
//    f.b    = { { { 1, 2, 3 }, 4 }, { { 4, 5, 6, 7 }, 5 }, { { 8, 9 }, 10 } };
//    f.a[0] = 1;
//    f.a[1] = 2;
//
//    triv_copyable tc;
//    /*tc.d   = 1;
//    tc.floateroo   = 2;
//    tc.i   = 5;
//    tc.testerroo.a = 6;
//    tc.testerroo.b = 1233;*/
//    std::ifstream in("testj.txt", std::ios::binary);
//
//    /*if (in.is_open()) {
//        carbon::deserialize<carbon::archive::json_input>(tc, in);
//        in.close();
//    }*/
//    std::ofstream out("testj.txt", std::ios::binary);
//    carbon::serialize<carbon::archive::json_output>(tc, out);
//}
