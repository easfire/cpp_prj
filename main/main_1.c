#include <stdio.h>
#include "max.h"
#include "min.h"

struct potentially_unsafe_struct {
      char id_1;
          char id_2;

              double weight_1;
                  double weight_2;
};

struct bad_struct {
      int id_1;
          double weight_1;

              int id_2;
                  double weight_2;
};
struct good_struct {
      int id_1;
          int id_2;

              double weight_1;
                  double weight_2;
};
int main(void) {
//    int a = 5;
//    int b = 6;
//
//    printf("%d\n", max(a,b));
//    printf("%d\n", gAll);

    struct potentially_unsafe_struct var;
    struct bad_struct var1;
    struct good_struct var2;

    printf("potential %d\n", sizeof(var));
    printf("bad       %d\n", sizeof(var1));
    printf("good      %d\n", sizeof(var2));

//    unsigned char c = 0xAA;
//    printf(" c=%hhx\n", c);
//    printf("~c=%hhx\n", (char)~c);
//    printf("-c=%hhx\n", (char)-c);

    unsigned char c = 0xA5;
    printf("   c=%d\n", c);
    printf("c<<2=%d\n", c<<2);

    int a = 0x80000000; // int 4bytes, 能表示的最大负数
    unsigned int b = 0x80000000;
    printf("a=%d\n", a);
    printf("b=%u\n", b);
    printf("a>>1=%d\n", a>>1);
    printf("b>>1=%u\n", b>>1);

    int LCR = 16;
    const unsigned int SBS = 1u << 2;
    const unsigned int PE = 1u << 3;

    printf("%d\n", LCR |= SBS|PE);
    printf("%d\n", LCR &= ~SBS);
    printf("%d\n", LCR &= ~(SBS|PE));

    return 0;
}
