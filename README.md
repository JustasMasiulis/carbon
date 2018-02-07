# carbon
A header only serialization library that prioritizes simplicity of use and speed.
The library requires a relatively new C++14 conformant compiler and comes with json and binary format support out of the box.

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

