#include <cstdio>

int main() {
    int x = 223;
    // 常引用 ref需要赋值, 指针就不需要
    int const &ref = x;

    printf("%d\n", ref);
    x = 1024;
    printf("%d\n", ref);
}
