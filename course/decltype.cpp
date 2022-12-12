#include <iostream>


int t;

int & func_ref() {
    return t;
}

int const & func_cref() {
    return t;
}

int func_val() {
    return t;
}

int main() {
//    std::cout << std::is_same_v<std::remove_reference_t<std::remove_const_t<int const &>>, int > << std::endl;
    std::cout << std::is_same_v<std::decay_t<int []>, int *> << std::endl;
    std::cout << std::is_same_v<std::decay_t<int &>, int> << std::endl;

    decltype(auto) a = func_cref();
    decltype(auto) b = func_ref();
    decltype(auto) c = func_val();
    return 0;
}
