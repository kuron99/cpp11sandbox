// verify moving vector element

#include <iostream>
#include <vector>
#include <cassert>

class C1 {
public:
    ~C1() noexcept = default;
    C1(C1 const& other) : x_(1) {}
    C1(C1&& other) noexcept : x_(100) {
//        other.x_ = 1000;
    }
    C1& operator=(C1 const& other) = delete;
    C1& operator=(C1&& other) noexcept = default;

    C1() : x_(0) {};
    C1(int x) : x_(x) {};
    int x_{};
};

C1 f1() {
    return C1{};
}



int main() {
    C1 c{f1()};
    assert(c.x_ == 0);
    return 0;
}

