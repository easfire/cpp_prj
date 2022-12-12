#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

int main() {

  std::vector<int> arr;
  std::mutex mtx;
  int num = 10;

  std::thread t1([&] {
    for (int i = 0; i < num; i++) {
        std::lock_guard grd(mtx);
        arr.push_back(1); 
        std::cout << "1" << std::endl;
    } 
  });

  std::thread t2([&] {
    for (int i = 0; i < num; i++) {
        std::lock_guard grd(mtx);
        arr.push_back(2); 
        std::cout << "2" << std::endl;
    } 
  });
  t1.join();
  t2.join();

  return 0;
}
