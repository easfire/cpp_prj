#include <cstdio>
#include <string>
#include <map>

// 函数返回引用，比如 懒汉单例模式
auto &product_table() {
    // 局部static 首次调用，初始化变量
    static std::map<std::string, int> instance;
    return instance;
}

int main() {
    product_table().insert({"cc", 30});
    product_table().emplace("aa", 10);
    product_table().emplace("bb", 20);
    for (auto& [k, v]: product_table()) {
        printf("%s : %d\n", k.c_str(), v);
    }
}
