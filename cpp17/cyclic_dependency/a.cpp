// header cyclic dependency typically results in "xxxx not found" error

#include "a.h"
#include <iostream>

int main() {
    std::cout << "main" << std::endl;

    x::A a{};
    x::B b{};

}
