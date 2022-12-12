#include <cstdio>

void hello();

struct monkey {
  int weight;
  float height;
};

typedef struct book {
  int x;
  int y;
} Book;

int main() {
  hello();
  Book b = {1,2};
  printf("book is %d, %d\n", b.x, b.y);
  return 0;
}
