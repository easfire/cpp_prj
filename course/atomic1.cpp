#include <iostream>
#include <thread>
#include <atomic>

int main() {
    std::atomic<int> counter = 0;
    const int num = 10000;

    std::thread t1([&] {
        for (int i = 0; i < num; i++) {
            counter = counter + 1; 
        }
    });

    std::thread t2([&] {
        for (int i = 0; i < num; i++) {
            counter = counter + 1; 
        }
    });

    t1.join();
    t2.join();

    std::cout << counter << std::endl;

    return 0;
}
