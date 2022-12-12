#include <iostream>
#include <atomic>

int main() {
    std::atomic<int> counter;

    counter.store(3232);

    int old = counter.exchange(3);
    std::cout << "old= " << old << std::endl;

    int now = counter.load();
    std::cout << "now= " << now << std::endl;

    return 0;
}
