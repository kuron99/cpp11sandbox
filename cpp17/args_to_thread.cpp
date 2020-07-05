// you need std::ref to the parameters passed to std::thread constructor
// because std::thread receives in pass-by-value semantics so that pass-by-reference becomes distinguishable

#include <vector>
#include <thread>
#include <iostream>

int f(std::vector<int>& v) {
    for(auto& x : v) {
        std::cout << x << std::endl;
    }
    return 1;
}
int main() {
    std::vector<int> myvec{1,2,3};
    std::thread t{f, std::ref(myvec)};

    t.join();
}