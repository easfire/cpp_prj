#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <future>

void download(std::string file) {
  for (int i = 0; i < 10; i++) {
    std::cout << "Downloading " << file
        << " (" << i * 10 << "%)..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
  }
  std::cout << "Download complete: " << file << std::endl;
}

void interact() {
  //std::this_thread::sleep_for(std::chrono::milliseconds(1200));
  std::string name;
  std::cin >> name;
  std::cout << "Hi, " << name << std::endl;
}

int main() {

  std::shared_future<void> fret = std::async([&] {
    download("hello.zip");
  });
  //auto fret2 = fret;
  auto fret3 = fret;

  interact();
  fret3.wait();
  std::cout << "result: completed." << std::endl;
  return 0;
}
