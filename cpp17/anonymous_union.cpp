// we can leave a variable uninitialized when you put it in anonymous union
// class/struct can be unnamed

#include <array>
#include <iostream>

class DefaultUnconstructible {
public:
    DefaultUnconstructible() = delete;
    int x_;
};
class C1 {
public:
    C1() = default;
    ~C1() = default;
    C1(C1 const& other) = default;
    C1(C1&& other) = default;
    C1& operator=(C1 const& other) = default;
    C1& operator=(C1&& other) = default;
    union {
        std::array<DefaultUnconstructible, 3> array_;
    };
};

class C2 {
public:
    class {
    public:
        int x_;
        int y_;
    };
};

int main() {
    C1 c1{};
    std::cout << c1.array_[0].x_ << std::endl;
    C2 c2{};
    std::cout << c2.x_ << std::endl;
}
