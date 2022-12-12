#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <future>

int download(std::string file) {
  for (int i = 0; i < 10; i++) {
    std::cout << "Downloading " << file
        << " (" << i * 10 << "%)..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
  }
  std::cout << "Download complete: " << file << std::endl;
  return 404;
}

void interact() {
  //std::this_thread::sleep_for(std::chrono::milliseconds(1200));
  std::string name;
  std::cin >> name;
  std::cout << "Hi, " << name << std::endl;
}

int main() {
  std::future<int> fret = std::async(std::launch::deferred, [&] {
    return download("hello.zip");
  });

  interact();
  int ret = fret.get();
  std::cout << "result: " << ret << std::endl;
  return 0;
}
