#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <chrono>

class ThreadPool {
  std::vector<std::thread> m_pool;

public:
  void push_back(std::thread thd) {
    m_pool.push_back(std::move(thd));
  }

  ~ThreadPool() {
    for (auto &t: m_pool) t.join(); // 等待池内的线程全部指向完毕 
  }
};

ThreadPool tpool;

void download(std::string file) {
  for (int i = 0; i < 10; i++) {
    std::cout << "Downloading " << file
        << " (" << i * 10 << "%)..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
  }
  std::cout << "Download complete: " << file << std::endl;
}

void interact() {
  std::string name;
  std::cin >> name;
  //std::this_thread::sleep_for(std::chrono::milliseconds(1200));
  std::cout << "Hi, " << std::endl;
}

void func() {
  std::thread t1([&] {
        download("hello.zip");
  });
  // 移交t1的控制权给全局变量 pool列表，延长 t1 的生命周期
  tpool.push_back(std::move(t1));
}

int main() {
  func();
  interact();
  return 0;
}
