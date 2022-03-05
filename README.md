# overload
Header Only C++ implicit lambda overload struct. Use with `std::visit` and `std::variant` 
as if it was type safe switch-case. 

## Example usage
This struct is designed specifically to be used in conjunction with `std::variand` and 
`std::visit` like the example below. Note that `std::visit` prefers to use const references.
```c++
int main(int argc, char** argv) {
    std::variant<int,float,bool> example_variable = 3;
    std::visit(overload(
            [](const int& i){ std::cout << i << " integer" << std::endl; },
            [](const float& f){ std::cout << f << " float" << std::endl; },
            [](const bool& b){ std::cout << std::boolalpha << b << " bool" << std::endl; }
           ), example_variable);
    return 0;
}
```
If you don't want to define all of your type cases, you can even use the universal reference, like below. However
BE AWARE! The universal reference _will_ overrule other overloads defined after it, so make sure to put the universal 
reference overload as the last overload.
```c++
int main(int argc, char** argv) {
    std::variant<int,float,bool> example_variable = 3;
    std::visit(overload(
            [](auto&& v){ std::cout << v << std::endl; }
           ), example_variable);
    return 0;
}
```
