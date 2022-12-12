#include <stdio.h>

int f(void);

#define PI 3.1415926
#define PI2 2*PI // pi * 2

#define PRT printf("%f ", PI); \
            printf("%f\n", PI2);
#define cube(x) \
          ((x)*(x)*(x))
#define MIN(a,b) ((a)>(b)?(b):(a))

int gAll = 12;

int main(int argc, char const *argv[]) {
    f();
    f();
    f();
    return 0;
}

int f(void) {
    int k = 0;
    static int all = 1;

    printf("&k   =%p\n", &k);
    printf("&gAll=%p\n", &gAll);
    printf("&all =%p\n", &all);

    printf("at %s all is %d\n", __func__, all);
    all += 2;
    printf("at %s all is %d\n", __func__, all);
    printf("-------------\n");

    PRT;

    printf("%s: %d\n", __FILE__, __LINE__);
    printf("%s, %s\n", __DATE__, __TIME__);
    
    printf("%d\n", cube(5));

    printf("MIN is %d\n", MIN(3,20));
    return all;
}
