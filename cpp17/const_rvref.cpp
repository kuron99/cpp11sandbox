// the priority of function called with const (&, &&) qualifiers

#include <iostream>
#include <cassert>

class C1 {
public:
    int f1() && {
        std::cout << "f1 &&" << std::endl;
        return 0;
    }
    int f1() const && {
        std::cout << "f1 const &&" << std::endl;
        return 1;
    }
    int f1() const & {
        std::cout << "f1 const &" << std::endl;
        return 2;
    }
    int f1() & {
        std::cout << "f1 &" << std::endl;
        return 3;
    }
};

int main() {
    C1 c;
    const C1 cc;
    assert(0 == C1{}.f1());
    assert(1 == (const C1){}.f1());
    assert(2 == cc.f1());
    assert(3 == c.f1());
}