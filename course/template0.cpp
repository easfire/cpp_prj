#include <iostream>

template <class T>
T twice(T t) {
    return t * 2;
}
//
//int main() {
//    std::cout << twice<int>(21) << std::endl;
//    std::cout << twice<float>(3.24f) << std::endl;
//    std::cout << twice<double>(2.783) << std::endl;
//    return 0;
//}
int main() {
    std::cout << twice(21) << std::endl;
    std::cout << twice(3.24f) << std::endl;
    std::cout << twice(2.783) << std::endl;
    return 0;
}
