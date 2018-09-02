// whether *this should be copied or moved within clone()& or clone()&&
// Unlikely to cv-qualifier case, in menber function qualified with & and &&,
// "this" doesn't change - "this" is rvalue and *this is lvalue

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
    C1 * clone() & {
        // "this" is always C1* and *this is C1&
        static_assert(std::is_same<decltype(this), C1*>::value, "true");
        static_assert(std::is_same<decltype(*this), C1&>::value, "true");
        static_assert(!std::is_same<decltype(*this), C1&&>::value, "true");
        return new C1(*this);
    }
    C1 * clone() && {
        // "this" is always C1* and *this is C1&
        static_assert(std::is_same<decltype(this), C1*>::value, "true");
        static_assert(std::is_same<decltype(*this), C1&>::value, "true");
        static_assert(!std::is_same<decltype(*this), C1&&>::value, "true");
        return new C1(std::move(*this));
    }
private:
    int x_;
};

int main() {
    std::cout << "start main" << std::endl;
    std::cout << "clone lvalue" << std::endl;
    C1 c1{-1};
    assert(c1.clone()->x() == 2);
    std::cout << "clone rvalue" << std::endl;
    assert(C1{-2}.clone()->x() == 3);
    std::cout << "clone ptr" << std::endl;
    C1 * ptr = &c1;
    assert(ptr->clone()->x() == 2);
    std::cout << "end main" << std::endl;
}