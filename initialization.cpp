// initialize from various types
// - copy or move construct happens only when target is bare C1
//   - from const C1&, move is not possible, so copy construction occurs
//   - even when C1 is constructed from rvalue reference, move is required to mark move is allowed
// - if target is reference of any kind, lvalue reference can be created from any lvalue,
//   and rvalue from any rvalue (moved value) as long as const rule is not violated
// - const C1 & is in between C1& and C1&&, in that it can be bound to either lvalue/rvalue

// Compatibility Matrix (target is initialized by source without/with std::move
//
//   source >| C1          C1&         const C1&   C1&&
//           |
// target    |
// ----------|--------------------------------------------------------
// C1        | copy/move   copy/move   copy/copy   copy/move
// C1&       | ref /na     ref /na     na  /na     ref /na
// const C1& | ref /ref    ref /ref    ref /ref    ref /ref
// C1&&      | na  /ref    na  /ref    na  /na     na  /ref

// copy - target is copy constructed
// move - target is move constructed
// ref  - target reference refers source
// na   - compile error

#include <cassert>
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
    ~C1() {
        std::cout << "~C1()" << std::endl;
    }

    int x() const {
        return x_;
    }
private:
    int x_;
};

int f1(C1 c1) {
    return c1.x();
}
int f2(C1& c1) {
    return c1.x();
}
int f3(const C1& c1) {
    return c1.x();
}
int f4(C1&& c1) {
    return c1.x();
}

#define NAME(a,b) a ## b
#define DEF_C1(a) \
C1 c ## a {-1}; \
C1 rc ## a {-1}; \
C1 crc ## a {-1}; \
C1& lvr ## a = rc ## a; \
const C1& clvr ## a = crc ## a; \
C1&& rvr ## a = C1{-1};


int main() {
    DEF_C1(1)
    DEF_C1(2)
    DEF_C1(3)
    DEF_C1(4)

    assert(f1(c1) == 2);
    assert(f1(std::move(c1)) == 3);

    assert(f1(lvr1) == 2);
    assert(f1(std::move(lvr1)) == 3);

    assert(f1(clvr1) == 2);
    assert(f1(std::move(clvr1)) == 2); // move cannot change const, so copy constructed

    assert(f1(rvr1) == 2);   // rvalue reference not automatically moved
    assert(f1(std::move(rvr1)) == 3);

    assert(f2(c2) == -1);
    //assert(f2(std::move(c1)) == 3); // compile error - f2 accepts only lvalue - unable to call with move

    assert(f2(lvr2) == -1);
//    assert(f2(std::move(lvr)) == 3); // compile error - f2 accepts only lvalue - unable to call with move

//    assert(f2(clvr) == 2); // compile error - cannot init C1 & from const C1&
//    assert(f2(std::move(clvr)) == 2); // compile error - f2 accepts only lvalue - unable to call with move

    assert(f2(rvr2) == -1);
//    assert(f2(std::move(rvr)) == 3); // compile error - f2 accepts only lvalue - unable to call with move

    // const C1& can be bind almost all cases
    assert(f3(c3) == -1);
    assert(f3(std::move(c3)) == -1);

    assert(f3(lvr3) == -1);
    assert(f3(std::move(lvr3)) == -1);

    assert(f3(clvr3) == -1);
    assert(f3(std::move(clvr3)) == -1);

    assert(f3(rvr3) == -1);
    assert(f3(std::move(rvr3)) == -1);

//    assert(f4(c1) == 2); // compile error - f4 accepts only rvalue - should be called with move
    assert(f4(std::move(c4)) == -1);

//    assert(f4(lvr) == 2); // compile error - f4 accepts only rvalue - should be called with move
    assert(f4(std::move(lvr4)) == -1);

//    assert(f4(clvr) == 2); // compile error - f4 accepts only rvalue - should be called with move
//    assert(f4(std::move(clvr)) == 4); // move cannot change const, C1&& cannot be init by const C1&&

//    assert(f4(rvr) == 2); // compile error - f4 accepts only rvalue - should be called with move
    assert(f4(std::move(rvr4)) == -1);
}