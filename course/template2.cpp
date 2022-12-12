#include <cstdio>

int main() {
    int x = 223;
    int &ref = x;
    // 也可以用 auto &ref = x; 自动类型推导
    printf("%p\n", &x);
    printf("%p\n", &ref);
    ref = 42;
    printf("%d\n", x);
    x = 1024;
    printf("%d\n", ref);
}
