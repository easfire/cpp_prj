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
        std::unique_lock grd(mtx);
        arr.push_back(1); 
        printf("outside of lock 11 \n");
    } 
  });

  std::thread t2([&] {
    for (int i = 0; i < num; i++) {
    // defer_lock 实际没有上锁
        std::unique_lock grd(mtx, std::defer_lock);
        printf("before lock \n");
        grd.lock();
        arr.push_back(2); 
        grd.unlock();
        printf("outside of lock 22 \n");
    } 
  });

  t1.join();
  t2.join();

  return 0;
}
