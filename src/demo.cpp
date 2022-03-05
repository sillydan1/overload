#include <iostream>
#include <variant>
#include <overload.h>

int main(int argc, char** argv) {
    std::variant<int,float,bool> example_variable = 3;
    std::visit(overload(
            [](const int& i){ std::cout << i << " integer" << std::endl; },
            [](const float& f){ std::cout << f << " float" << std::endl; },
            [](const bool& b){ std::cout << std::boolalpha << b << " bool" << std::endl; }),
           example_variable);
    return 0;
}
