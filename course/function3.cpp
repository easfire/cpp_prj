#include <iostream>

template <class Func>

void call_twice(Func const &func) {
    std::cout << func(0) << std::endl;
    std::cout << func(1) << std::endl;
    std::cout << "func size is " << sizeof(Func) << std::endl;
}

//int main() {
//    auto twice = [](int n) {
////    auto twice = [](int n) -> int {
//        return n * 2;
//    };
//    call_twice(twice);
//    return 0;
//}

int main() {
    // 可读
    int fac = 2;
    // 可写
    int counter = 0;
    // 闭包(closure), 可以引用定义位置所有的变量。
    // 可变引用,非常引用
    auto twice = [&] (int n) {
//    auto twice = [](int n) -> int {
        counter++;
        return n * fac;
    };
    call_twice(twice);
    std::cout << "count: " << counter << "!" << std::endl;
    return 0;
}
