// pointer to member - variable is 8 bytes, but function is 16 bytes

#include <iostream>

class C1 {
public:
    C1() : x_(1), y_(2) {}
    int x_;
    int y_;
};

class C2 {
public:
    int x2_;
    int y2_;
    void f2() {}
};

class C3 : public C1, C2 {
public:
    int z_;
};

int main() {
    C1 c;
    int C1::* px = &C1::x_;
    int C1::* py = &C1::y_;
    int C3::* pz = &C3::z_;
    static_assert(sizeof(px) == 8);
    static_assert(sizeof(py) == 8);
    static_assert(sizeof(&C3::x_) == 8);
    static_assert(sizeof(&C2::f2) == 16);
    std::cout << "c.x = " << c.*px << " c.y = " << c.*py << std::endl;
}