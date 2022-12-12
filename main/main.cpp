#include <stdio.h>

typedef union {
    int i;
    char ch[sizeof(int)]; // 兼容不同平台的int大小
} CHI;

int main(int argc, char const *argv[]) {
    CHI chi;
    int i;
    chi.i = 1234;

    for (i = 0; i < sizeof(int); i++) {
        printf("%02hhX", chi.ch[i]);
    }
    printf("\n");

//    union An {
//        int  i;
//        char c;
//        char ch[sizeof(int)];
//    } elt1, elt2;
//
//    elt1.i = 4;
//    //elt2.c = 'a';
//    elt2.i = 0xDEADBEEF;
//
//    for (int i = 0; i < sizeof(int); i++) {
//        printf("%02hhX", elt2.ch[i]);
//    }
//    printf("\n");

    return 0;
}
