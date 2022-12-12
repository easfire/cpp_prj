#include <iostream>
#include <functional>

template <class Func>
void call_twice(Func const &func) {
    std::cout << func(3.14f) << std::endl; 
    std::cout << func(21) << std::endl; 
}

int main() {
    auto twice = [] (auto n) {
        return n * 2;
    };
    call_twice(twice);
    return 0;
}
