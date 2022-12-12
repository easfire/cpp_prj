#include <iostream>
#include <thread>
#include <atomic>

int main() {
    const int num = 10000;

    std::atomic<int> counter;
    counter.store(0);

    std::thread t1([&] {
        for (int i = 0; i < num; i++) {
            counter.fetch_add(1);
        }
    });

    std::thread t2([&] {
        for (int i = 0; i < num; i++) {
            counter.fetch_add(1);
        }
    });

    t1.join();
    t2.join();

    std::cout << counter.load() << std::endl;

    return 0;
}
