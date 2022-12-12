#include <iostream>
#include <tuple>

int main() {
    auto tup = std::tuple(3, 3.14f, 'h');

//    auto first = std::get<0>(tup);
//    auto second = std::get<1>(tup);
//    auto third = std::get<2>(tup);
    // C++17
    auto &[first, second, third] = tup;

    std::cout << std::get<0>(tup) << std::endl;
    first = 42;
    std::cout << std::get<0>(tup) << std::endl;

    std::cout << second << std::endl;
    std::cout << third << std::endl;
    return 0;
}
