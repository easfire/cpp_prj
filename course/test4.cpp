#include <iostream>
#include <thread>
#include <string>
#include <vector>

std::vector<std::jthread> pool;

void download(std::string file) {
  for (int i = 0; i < 10; i++) {
    std::cout << "Downloading " << file
        << " (" << i * 10 << "%)..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
  }
  std::cout << "Download complete: " << file << std::endl;
}

void interact() {
//  std::string name;
//  std::cin >> name;
  std::this_thread::sleep_for(std::chrono::milliseconds(1200));
  std::cout << "Hi, " << std::endl;
}

void func() {
  std::jthread t1([&] {
        download("hello.zip");
      });
  // 移交t1的控制权给全局变量 pool列表，延长 t1 的生命周期
  pool.push_back(std::move(t1));
  // t1.detach();
  // 退出函数体，会销毁 t1 线程句柄.
}

int main() {
  func();
  interact();
  return 0;
}
