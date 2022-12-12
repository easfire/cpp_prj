# 1 "max.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "max.c"
# 1 "max.h" 1



int max(int a, int b);
extern int gAll;

struct Node {
    int value;
    char* name;
};
# 2 "max.c" 2

int gAll = 12;

int max(int a, int b) {
    return a > b ? a : b;
}
