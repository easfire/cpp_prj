#include <cstdio>

//void test(int & a) {
//    printf("int & %p\n", &a);
//}

void test(int &) {
    printf("int &\n");
}

void test(int const &) {
    printf("int const &\n");
}

void test(int &&) {
    printf("int &&\n");
}

int main() {
    int a = 0;
    int *p = &a;

    test(a);
    test(*p);
    test(p[a]);

    // 1是临时性存在于内存中，语句执行完就不存在了
    test(1);
    test(a + 1);
    test(*p + 1);
    
    const int b = 3;
    test(b);
    test(b + 1);
}
