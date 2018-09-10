
#include <utility>
#include <memory>
#include <iostream>
#include <cassert>
#include "boost/type_index.hpp"


class MC1 {
public:
    template <typename T>
    void func1(T x) {
        std::cout << "func1(T)" << std::endl;
//        return std::forward(x);
    }
};

template <typename T>
void g(T&& x) {
    std::cout << "type T : " << boost::typeindex::type_id_with_cvr<T&&>() << std::endl;
    MC1<T&&> mc1{};
    mc1.func1(std::forward<T&&>(x));
}

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

int main() {
    C1 c1{-1};
    g(c1);
    g(C1{-2});
}
