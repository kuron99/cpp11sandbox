// verify we can pass initializer_list and convert to vector implicitly

#include <vector>
#include <string>
#include <iostream>
#include <cassert>

class C0 {
public:
    C0(int x) : x_(x) {}
    C0() : x_(1) {
        std::cout << "C0()" << std::endl;
    }
    C0(const C0&) : x_(2) {
        std::cout << "C0(const C0&)" << std::endl;
    }
    C0(C0&&) : x_(3) {
        std::cout << "C0(C0&&)" << std::endl;
    }
    int x_;
};
class C1 {
public:
    C1() : x_(1) { }
    C1(const C1&) : x_(2) {}
    C1(std::vector<C0>& v) : v_(std::move(v)), x_{3} {}
    C1(std::vector<C0> v) : v_(std::move(v)), x_{4} {}
    std::vector<C0> v_;
    int x_;
};

int main() {
    C0 c0{-1};
    C1 c1{{c0}}; // create vector from initializer_list

    assert(c1.v_[0].x_ == 2); // content of the initilizer list is copied
    assert(c1.x_ == 4);
}
