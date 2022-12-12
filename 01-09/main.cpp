#include <cstdio>

#include "hello.h"
#include "goodbye.h"

// 递归使用头文件
int main() {
  MyClass mc;
  mc.m_number = 42;
  hello(mc);
  goodbye(mc);
  return 0;
}
