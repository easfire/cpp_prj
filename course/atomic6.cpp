#include <iostream>
#include <atomic>

int main() {
    boolalpha(std::cout);
    std::atomic<int> counter;

    counter.store(2);
    
    int old = 1;
    bool equal = counter.compare_exchange_strong(old, 3);
    std::cout << "equal= " << equal << std::endl;
    std::cout << "old= " << old << std::endl;

    int now = counter.load();
    std::cout << "cnt= " << now << std::endl;

    old = 2;
    equal = counter.compare_exchange_strong(old, 3);
    std::cout << "equal= " << equal << std::endl;
    std::cout << "old= " << old << std::endl;

    now = counter.load();
    std::cout << "cnt= " << now << std::endl;

    return 0;
}

