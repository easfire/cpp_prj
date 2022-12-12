#include <iostream>
#include <thread>
#include <mutex>

int main() {
    int counter = 0;
    const int num = 10000;

    std::mutex mtx;

    std::thread t1([&] {
        for (int i = 0; i < num; i++) {
            mtx.lock();
            counter += 1; 
            mtx.unlock();
        }
    });

    std::thread t2([&] {
        for (int i = 0; i < num; i++) {
            mtx.lock();
            counter += 1; 
            mtx.unlock();
        }
    });

    t1.join();
    t2.join();

    std::cout << counter << std::endl;

    return 0;
}
