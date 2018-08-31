// same as longevity1.cpp for T&& - longevity doesn't work when repeated

#include <string>
#include <iostream>

class C1 {
public:
    C1() : x_(1) {
        std::cout << "C1()" << std::endl;
    }
    C1(const C1&) : x_(2) {
        std::cout << "C1(const C1&)" << std::endl;
    }
    C1(C1&&) : x_(3) {
        std::cout << "C1(C1&&)" << std::endl;
    }
    C1(int x) : x_(x) {
        std::cout << "C1(int)" << std::endl;
    }
    virtual ~C1() {
        std::cout << "~C1()" << std::endl;
    }

    int x() const {
        return x_;
    }
private:
    int x_;
};

C1&& mymove(C1&& c1) {
   return static_cast<C1&&>(c1);
}

int main() {
    C1&& c1 = mymove(C1(-1));
    std::cout << c1.x() << std::endl;
}

