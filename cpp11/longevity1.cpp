// longevity doesn't work when repeated
// longevity happens only once withing the function receiving const C1 &, and when it returns as const C1&, it's not alive any more.
// The code below doesn't crash with luck, but address sanitizer warns "Stack-use-after-scope"

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
const C1& foo( const C1& s ){
    std::cout << "exiting foo()" << std::endl;
    return s;
}
int main() {
    const C1& bar = foo( C1(100) );
    std::cout << "exited foo()" << std::endl;
    std::cout << bar.x() << std::endl;
}