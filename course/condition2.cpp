#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

int main() {

    std::condition_variable cv;
    std::mutex mtx;

    std::vector<int> foods;

    std::thread t1([&] {
        for (int i = 0; i < 2; i++) {
            std::unique_lock lock(mtx); 
            cv.wait(lock, [&] {
                return foods.size() != 0;    
            });
            auto food = foods.back();
            foods.pop_back();
            lock.unlock();

            std::cout << "t1 got food: " << food << std::endl; 
        }     
    });

    std::thread t2([&] {
        for (int i = 0; i < 2; i++) {
            std::unique_lock lock(mtx); 
            cv.wait(lock, [&] {
                return foods.size() != 0;    
            });
            auto food = foods.back();
            foods.pop_back();
            lock.unlock();

            std::cout << "t2 got food: " << food << std::endl; 
        }     
    });
    
    foods.push_back(42);
    cv.notify_one();
    foods.push_back(223);
    cv.notify_one();

    foods.push_back(6666);
    foods.push_back(181891);
    cv.notify_all();

    t1.join();
    t2.join();

    return 0;
}
