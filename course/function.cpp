#include <cstdio>

//void say_hello() {
//    printf("hello world.\n");
//}
//
//void call_twice(void func()) {
//    func();
//    func(); 
//}
//
//int main() {
//    call_twice(say_hello);
//    return 0;
//}

// 函数参数格式是匹配的
void print_number(int n) {
    printf("hello world %d\n", n);
}

void call_twice(void func(int)) {
    func(0);
    func(1); 
}

int main() {
    call_twice(print_number);
    return 0;
}
