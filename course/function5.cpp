#include <iostream>

template <class Func>

void call_twice(Func const &func) {
    std::cout << func(0) << std::endl;
    std::cout << func(1) << std::endl;
    std::cout << "func size is " << sizeof(Func) << std::endl;
}

// [&] 捕获的是引用，是fac的地址，而 make_twice 已经返回，导致 fac的引用变成悬浮指针
// 总之，使用[&] 需要保证 lambda对象的生命周期不超过它捕获的引用的寿命。
auto make_twice(int fac) {
//    return [&] (int n) {
//    通过[=] 捕获fac的值，而非引用
//    会造成对引用变量的拷贝，性能不如 [&]
    return [=] (int n) {
        return n * fac;
    };
}

int main() {
  // 创建twice 这个lambda局部表达式对象，再把它传给 call_twice
    auto twice = make_twice(2);
    call_twice(twice);
    return 0;
}
