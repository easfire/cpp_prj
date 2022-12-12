#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

int main() {
    std::condition_variable cv;
    std::mutex mtx;
    bool ready = false;

    std::thread t1([&] {
        std::unique_lock lock(mtx);    
        cv.wait(lock, [&] {return ready;});
        lock.unlock();

        std::cout << "t1 is awake" << std::endl;
    });
    
    std::cout << "notifying not ready" << std::endl;
    cv.notify_one();  

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    ready = true;
    std::cout << "notifying ready" << std::endl;
    cv.notify_one();

    t1.join();

    return 0;
}
