// ExecutionPolicy not implemented in C++17 as of gcc 7

#include <vector>
#include <algorithm>
#include <iostream>

const static int DATASIZE = 1001001001;
int main() {
    std::vector<int> v{};
    v.reserve(DATASIZE);
    for(int i=0; i < DATASIZE; ++i) {
        v.emplace_back(i);
    }
    std::sort(ExecutionPolicy::, v.begin(), v.end());
    for(int i=0; i < DATASIZE; ++i) {
        std::cout << v[i] << std::endl;
    }
}