#include <iostream>
#include <tuple>
#include <cmath>

std::tuple<bool, float> mysqrt(float x) {
    if (x >= 0.f) {
        return {true, std::sqrt(x)};
    } else {
        return {false, 0.0f}; 
    } 
}

int main() {
    auto [success, value] = mysqrt(-10.f);
    if (success) {
        printf("success, result: %f\n", value);
    } else {
        printf("error, result: %f\n", value);
    }
    return 0;
}
