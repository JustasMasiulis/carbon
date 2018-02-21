# carbon
A header only serialization library that prioritizes simplicity of use and speed.
The library requires a relatively new C++14 conformant compiler and comes with json and binary format support out of the box.

I am no longer working on the library - json serialization/deserialization works for probably all standard types, but while implementing it I broke binary serialization. If you are interested in this library please open an issue and I will try to fix/implement support for what you need. The reason for my loss of interest is the fact that it is a lot of work to hand craft every archive for maximum performance - what works best for binary doesnt work for json and vice versa. Due to me not wanting to sacrifice any performance it is also not possible to specialize serialization for types you dont have access to.

## small example
```cpp
struct foo {
    std::vector<bar>             vec;
    std::tuple<std::string, baz> tup;
    CARBON_NAMED_SERIALIZABLE(foo, vec, tup);
}
std::ofstream out("output.txt");
foo f{};
carbon::deserialize<carbon::archive::json>(f, out);
```

## reference

