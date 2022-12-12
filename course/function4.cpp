#include <iostream>

template <class Func>

void call_twice(Func const &func) {
    std::cout << func(0) << std::endl;
    std::cout << func(1) << std::endl;
    std::cout << "func size is " << sizeof(Func) << std::endl;
}

// 创建 twice函数
auto make_twice() {
    return [] (int n) {
        return n * 2;
    };
}

int main() {
  // 创建twice 这个lambda局部表达式对象，再把它传给 call_twice
    auto twice = make_twice();
    call_twice(twice);
    return 0;
}
