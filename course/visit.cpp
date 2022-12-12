#include <iostream>
#include <variant>

void print(std::variant<int, float> const &v) {
  // 利用lambda表达式，多次编译的特点
    std::visit([&] (auto const &t) {
        std::cout << t << std::endl;
    }, v);
}

int main() {
    std::variant<int, float> v = 3;
    print(v);
    v = 3.14f;
    print(v);
    return 0;
}
