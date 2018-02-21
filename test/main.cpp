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
    void copy(T)
    {}
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
        A& archive;

        template<class... Args>
        inline bar b(Args&&... args)
        {
            return bar(bar::carbon_type<bar, A>(archive),
                       std::forward<Args>(args)...);
        }
        char        c() {}
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
