#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

int main() {
    const int num = 100;

    std::atomic<int> counter;
    counter.store(0);

    std::vector<int> data(num * 2);

    std::thread t1([&] {
        for (int i = 0; i < num; i++) {
            int index = counter.fetch_add(1);
            data[index] = i;
        }
    });

    std::thread t2([&] {
        for (int i = 0; i < num; i++) {
            int index = counter.fetch_add(1);
            data[index] = i + num;
        }
    });

    t1.join();
    t2.join();

    std::cout << counter.load() << std::endl;
    std::cout << data[rand()%(num*2)] << std::endl; 

    return 0;
}
