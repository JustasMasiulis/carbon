#include "../include/carbon.hpp"
#include "../include/carbon/detail/visit_members.hpp"

struct bar {
    template<class Carbon>
    bar(Carbon c, int x, int y) : i(c.i() * x), f(c.f() * y)
    {}
    int   i;
    float f;
};


struct fake_arch {
    template<class T>
    void copy(T) {}
};

struct foo {
    template<class Carbon>
    foo(Carbon c, const char* test_arg) : b(c.b(5, 6))
    {
        c.unpack_rest(*this);
    }
    bar  b;
    char c;

    constexpr static auto carbon_members{ std::make_tuple(&foo::b, &foo::c) };
    template<class T, class A>
    struct carbon_type {
        A&   archive;
        bool unpacked[2] = false;

        template<class... Args>
        inline bar b(Args&&... args)
        {
            unpacked[0] = 1;
            return bar(bar::carbon_type<bar, A>(archive), std::forward<Args>(args)...);
        }
        char        c() {
            
        
        }
        inline void unpack_rest(T* this_)
        {
            // if (!unpacked[0])
            //   this_.*std::get<0>(member_pointers) = ...;
            // if (!unpacked[1])
            //  this_.std::get<1>(member_pointers) = ...;
        }
    };

    // constexpr static auto ml{ carbon::detail::make_members_list(&foo::i, &foo::f)
    // };
    // CARBON_SERIALIZABLE(foo, i, f, b, c);
    // CARBON_NAMED_SERIALIZABLE(foo, tc, i, a);
};

int main()
{
    // float archive;
    // carbon::construct<foo>(archive, "wubadubdub");
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
