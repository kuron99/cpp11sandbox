// copy construct happens with static_cast<C1>
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

int main() {
    C1 c1{-1};
    assert(c1.x() == -1);
    assert(static_cast<C1>(c1).x() == 2);    // copy temp
    assert(static_cast<C1 &>(c1).x() == -1);
    assert(static_cast<C1 &&>(c1).x() == -1);

    C1 &lvalue_ref = c1;
    assert(lvalue_ref.x() == -1);
    assert(static_cast<C1>(lvalue_ref).x() == 2); // copy temp
    assert(static_cast<C1 &>(lvalue_ref).x() == -1);
    assert(static_cast<C1 &&>(lvalue_ref).x() == -1);

    C1 &&rvalue_ref = C1{-1};
    assert(rvalue_ref.x() == -1);
    assert(static_cast<C1>(rvalue_ref).x() == 2); // copy temp
    assert(static_cast<C1 &>(rvalue_ref).x() == -1);
    assert(static_cast<C1 &&>(rvalue_ref).x() == -1);
    cout << "end of main" << endl;
}
