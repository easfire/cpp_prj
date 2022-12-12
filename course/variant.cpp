#include <iostream>
#include <variant>

int main() {
    std::variant<int, float> v = 3;
    std::cout << std::get<0>(v) << std::endl;

    v = 3.14f;
    std::cout << std::get<1>(v) << std::endl;
    return 0;
}
