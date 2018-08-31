// check what type is "this"

#include <iostream>
#include <type_traits>
#include "boost/type_index.hpp"

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
        std::cout << boost::typeindex::type_id_with_cvr<decltype(this)>() << std::endl;
//        static_assert(std::is_same<decltype(this), C1*&>::value, "true");
        return new C1(*this);
    }
    C1 * clone() && {
        std::cout << boost::typeindex::type_id_with_cvr<decltype(this)>() << std::endl;
//        static_assert(std::is_same<decltype << std::endl;(this), C1*>::value, "true");
        return new C1(std::move(*this));
    }
private:
    int x_;
};

int main() {
    std::cout << "start main" << std::endl;
    std::cout << "clone lvalue" << std::endl;
    C1 c1{-1};
    c1.clone();
    std::cout << "clone rvalue" << std::endl;
    C1{-2}.clone();
    std::cout << "clone ptr" << std::endl;
    C1 * ptr = &c1;
    ptr->clone();
    std::cout << "end main" << std::endl;
    C1 *& ptr2 = ptr;
}