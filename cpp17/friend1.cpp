// why firiend function cannot be specified with function attributes

#include <iostream>
#include <cstdlib>
#include <cassert>

namespace ns {

class C1 {
public:
    [[nodiscard]] friend int f1(C1& c); // freind func. declared/defined inline only callable via ADL

    int f2() ;
private:
    int x_{3};
};

int f1(C1& c) {
    return c.x_;
}

int C1::f2() {
    return f1(*this);
}

}

int main() {
    ns::C1 c;
    std::cout << c.f2() << std::endl;
    f1(c);
}

