#include <iostream>

template <class T>
T twice(T t) {
    return t * 2;
}

// 模板特例
// 他会自动和已有模板 twice<T>(T) 之间相互重载
std::string twice(std::string t) {
    return t + t;
}

int main() {
    std::cout << twice(21) << std::endl;
    std::cout << twice(3.24f) << std::endl;
    std::cout << twice(2.783) << std::endl;
    std::cout << twice(std::string("hello")) << std::endl;
    return 0;
}
