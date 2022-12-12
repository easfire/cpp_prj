#include <iostream>
#include <vector>

template <class T1, class T2>

auto add(std::vector<T1> const &a, std::vector<T2> const &b) {
  // 通过实际传参 a b的类型，判断  T1{} + T2{}的类型
    using T0 = decltype(T1{} + T2{});
    std::vector<T0> ret;
    for (size_t i = 0; i < std::min(a.size(), b.size()); i++) {
        ret.push_back(a[i] + b[i]);
    }
    return ret;
}

int main() {
    std::vector<int> a = {2, 3, 4};
    std::vector<float> b = {0.5f, 1.0f, 2.5f};

    auto c = add(a, b);
    for (size_t i = 0; i < c.size(); i++) {
        std::cout << c[i] << std::endl;
    }
    return 0;
}
