#include <cstdio>

int main() {
    int x = 223;
    int *ref = &x;
    printf("%p\n", ref);
    printf("%p\n", &x);
    *ref = 42;
    printf("%d\n", x);
    x = 1024;
    printf("%d\n", *ref);
}
