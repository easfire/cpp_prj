#include <cstdio>

void print_float(float n) {
    printf("Float %f\n", n);
}

void print_int(int n) {
    printf("Int %d\n", n);
}

// 这样 call_twice 会自动对每个不同的func类型编译一遍，
// 从而允许编译器更好地进行自动适配与优化
template <class Func>
void call_twice(Func func) {
    func(0);
    func(1);
}

int main() {
    call_twice(print_float);
    call_twice(print_int);
    return 0;
}
