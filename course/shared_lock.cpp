#include <iostream>
#include <thread>
#include <vector>
#include <shared_mutex>

class MTVector {
    std::vector<int> m_arr;
    mutable std::shared_mutex m_mtx;

public:
    void push_back(int val) {
      std::unique_lock grd(m_mtx);
      m_arr.push_back(val);
    }
    
    size_t size() const {
      std::shared_lock grd(m_mtx);
      return m_arr.size(); 
    }
};

int main() {
    int num = 1000;
    MTVector arr;

    std::thread t1 ([&] () {
        for (int i = 0; i < num; i++) {
        //每次写数据，都调用一次加锁和解锁，非常低效
            arr.push_back(i); 
        }    
    });

    std::thread t2 ([&] () {
        for (int i = 0; i < num; i++) {
            arr.push_back(num + i); 
        }    
    });

    t1.join();
    t2.join();

    std::cout << arr.size() << std::endl;
    return 0;
}
