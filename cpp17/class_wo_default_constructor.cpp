// class without default constructor is hard to handle

#include <cassert>
class C1 {
public:
    C1(int x) : x_(x) {}
    virtual ~C1() = default;
    int x_{};
};

class C2 : public C1 {
public:
    using C1::C1;
    C2(int y) : y_(y), C1(9) { // need to call C1, otherwise compile error
    }
    int y_{};
};

class C3 : public C1 {
public:
    using C1::C1;
    int y_{};
};
int main() {
    //C1 c; // compile error
    //C1 c{};
    C1 c{3};

    C2 c2{4};
    assert(c2.y_ == 4);
    assert(c2.x_ == 9);
    C3 c3{4};
    assert(c3.y_ == 0);
    assert(c3.x_ == 4);
}