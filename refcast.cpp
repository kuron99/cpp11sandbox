// Difficult to understand cast between non-reference type - basic idea is variable initialization semantics in T temp = expr,
// but sometimes constructor is called and others not.
// On the other hand, reference types are easy - simply handle the source as target reference type. e.g. C&& -> C&, C -> C&&
// No constructors are involved unexpectedly.

#include <iostream>
#include <cassert>

using namespace std;

class C1 {
public:
    C1() : x_(1) {
        cout << "C1()" << endl;
    }

    C1(int x) : x_(x) {
        cout << "C1(int)" << endl;
    }

    C1(const C1 &) : x_(2) {
        cout << "C1(const C1&)" << endl;
    }

    C1(C1 &&) : x_(3) {
        cout << "C1(C1&&)" << endl;
    }

    ~C1() {
        cout << "~C1()" << endl;
    }

    int x() { return x_; }

private:
    int x_;
};

const C1& factory(const C1& c1) {
    return C1{};
}

int main() {
    C1 c1{-1};
    assert(c1.x() == -1);
    assert(static_cast<C1>(c1).x() == 2);    // temp obj created with copy ctor
    assert(static_cast<C1 &>(c1).x() == -1);
    assert(static_cast<C1 &&>(c1).x() == -1);
    assert(static_cast<C1>(std::move(c1)).x() == 3);    // cast from rvalue - temp obj created with move ctor
    assert(static_cast<C1>(C1{-1}).x() == -1);          // cast from rvalue - different behavior with above. Probably a valid short cut
//    assert(static_cast<C1&>(C1{-1}).x() == 3);        // compile error - C1& unable to initialize from rvalue
//    assert(static_cast<C1&>(std::move(c1)).x() == 3);        // compile error - C1& unable to initialize from rvalue
    assert(static_cast<C1&&>(std::move(c1)).x() == -1);
    assert(static_cast<C1&&>(C1{-1}).x() == -1);

    C1 &lvalue_ref = c1;
    assert(lvalue_ref.x() == -1);
    assert(static_cast<C1>(lvalue_ref).x() == 2); // temp obj created with copy ctor
    assert(static_cast<C1>(std::move(lvalue_ref)).x() == 3); // temp obj created with move ctor
    assert(static_cast<C1 &>(lvalue_ref).x() == -1);
    assert(static_cast<C1 &&>(lvalue_ref).x() == -1);

    C1 &&rvalue_ref = C1{-1};
    assert(rvalue_ref.x() == -1);
    assert(static_cast<C1>(rvalue_ref).x() == 2); // temp obj created with copy ctor
    assert(static_cast<C1>(std::move(rvalue_ref)).x() == 3); // temp obj created with move ctor
    assert(static_cast<C1 &>(rvalue_ref).x() == -1);
    assert(static_cast<C1 &&>(rvalue_ref).x() == -1);
    cout << "end of main" << endl;
}
