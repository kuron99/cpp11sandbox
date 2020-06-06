// std::hash can apply to double, then +0 and -0 are mapped to 0 as they are equivalent
// nan's have different value representation, and are mapped to different values

#include <iostream>
#include <cmath>
#include <cassert>

int main() {
    double z0 = 0.0;
    double z1 = -0.0;

    double one = 1.0;
    std::cout << std::hex << z0 << std::endl;
    std::cout << std::hex << z1 << std::endl;
    std::cout << std::hex << one << std::endl;
    std::cout << std::hex << std::hash<double>()(z0) << std::endl;
    std::cout << std::hex << std::hash<double>()(z1) << std::endl;
    std::cout << std::hex << std::hash<double>()(one) << std::endl;

    double nan1 = std::nan("1");
    double nan2 = std::nan("2");
    std::cout << std::hex << std::hash<double>()(nan1) << std::endl;
    std::cout << std::hex << std::hash<double>()(nan1) << std::endl;
    std::cout << std::hex << std::hash<double>()(nan2) << std::endl;

    double nan1_minus = -std::nan("1");
    std::cout << std::hex << nan1_minus << std::endl;
    std::cout << std::hex << std::hash<double>()(nan1_minus) << std::endl;

    assert(nan1 != nan1);
}