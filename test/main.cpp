#include "../include/carbon.hpp"
#include "../include/carbon/detail/visit_members.hpp"

struct bar {
    int   i;
    float f;
};

struct fake_arch {
    template<class T>
    void copy(T)
    {}
};

struct foo {
    bar  b;
    char c;

    template<class T>
    struct carbon_type {
        decltype(T::b)        b;
        decltype(T::c)        c;
        constexpr static auto target_members = std::make_tuple(&T::b, &T::c);
        constexpr static auto our_members    = std::make_tuple(&T::b, &T::c);
    };
    // foo(carbon_type<foo>&& c) : b(c.b) {}
};


int main()
{
    foo::carbon_type<foo> f;
    // float archive;
    // carbon::construct<foo>(archive, "wubadubdub");
}
