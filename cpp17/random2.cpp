// you can use uniform_real_distribution to get uniform distribution. But specifying double max/min values results in numbers around 1E308 or 1E-308.
// You rarely see values around [-1E100, 1E100]. This is because 1E308 is very big and dominant.

#include <random>
#include <iostream>

std::mt19937_64 mt{};


int main() {
    std::cout << std::numeric_limits<double>::lowest() << std::endl;
    std::cout << std::numeric_limits<double>::max() << std::endl;
    std::uniform_real_distribution<double> dist{std::numeric_limits<double>::lowest()/3.0, std::numeric_limits<double>::max()/3.0};
    for(int i=0 ; i < 1000; ++i) {
        std::cout << dist(mt) << std::endl;
    }
}