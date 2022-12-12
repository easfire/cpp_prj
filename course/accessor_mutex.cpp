#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

// 分离实际对象的存储和访问
class MTVector {
    std::vector<int> m_arr;
    std::mutex m_mtx;

public:
    class Accessor {
        MTVector &m_that;
        std::unique_lock<std::mutex> m_guard;   

      public:
        Accessor(MTVector &that) // Accessor访问者初始化时，先上一个锁 m_guard, 锁住 m_mtx
          : m_that(that), m_guard(that.m_mtx)
        {}

        void push_back(int val) const {
            return m_that.m_arr.push_back(val);
        }

        size_t size() const {
            return m_that.m_arr.size();
        }
    };
// 通过access函数，获取一个存储对象的访问者
    Accessor access() {
        return {*this};
    }
};

int main() {
    int num = 1000;
    MTVector arr;

    std::thread t1 ([&] () {
        // 一次上锁
        auto axr = arr.access();
        for (int i = 0; i < num; i++) {
            axr.push_back(i); 
        }    
        // 一次解锁
    });

    std::thread t2 ([&] () {
        auto axr = arr.access();
        for (int i = 0; i < num; i++) {
            axr.push_back(num + i); 
        }    
    });

    t1.join();
    t2.join();

    std::cout << arr.access().size() << std::endl;

    return 0;
}
