#include <iostream>
#include <variant>

void print(std::variant<int, float> const &v) {
  // 利用lambda表达式，多次编译的特点
    std::visit([&] (auto const &t) {
        std::cout << t << std::endl;
    }, v);
}

// std::visit 会自动罗列出所有的排列组合， lambda会被编译n^2次，编译可能会变慢
// 标准库可以保证运行时为O(1)，用函数指针实现分支，非暴力if-else
auto add(std::variant<int, float> const &v1,
         std::variant<int, float> const &v2) {
    std::variant<int, float> ret;
    std::visit([&] (auto const &t1, auto const &t2) {
        ret = t1 + t2;
    }, v1, v2);
    return ret;
}

int main() {
    std::variant<int, float> v = 3;
    print(add(v, 3.14f));
    return 0;
}
