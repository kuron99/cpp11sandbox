// anonymous struct is not part of C++
// no warning/errors raised -Wall -Wextra
// -Wpedantic raises a warning "warning: ISO C++ prohibits anonymous structs [-Wpedantic]"

#include <cstdint>
#include <cassert>
#include <iostream>

union U1 {
    std::int32_t a_;
    struct {
        int x_:16;
        int y_:16;
    };
};

int main() {
    U1 u;
    u.a_ =1;
    u.x_ =2;

    assert(u.x_ == 2);
    std::cout << u.x_ << std::endl;
    std::cout << u.y_ << std::endl;
}