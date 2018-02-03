# carbon
Light and easy to use serialization library.

## Installation
The library is header only so simply copy pasting it to your project is sufficient.

## Small example
To create a serializable structure all that has to be done is use a simple macro `CARBON_SERIALIZABLE(class_name, class_members...)`
If you want to serialize private members the macro has to be used inside the class.

```cpp
struct foo {
    std::vector<bar> vec;
    int              arr[5];
    CARBON_SERIALIZABLE(foo, vec, arr);
};
```

To serialize the data there are a bunch of overloaded functions that handle the conversions
```cpp
// archive can be a c++ stream, pointer to uint8_t etc
carbon::serialize(class_instance, archive);
carbon::deserialize(class_instance, archive);
```
