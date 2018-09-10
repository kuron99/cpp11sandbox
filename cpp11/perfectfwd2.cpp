
#include <utility>
#include <memory>
#include <iostream>
#include <cassert>
#include <type_traits>
#include "boost/type_index.hpp"


class C1 {
};

template<typename T>
void g1(T &&x) {
    std::cout << "type T : " << boost::typeindex::type_id_with_cvr<T>() << std::endl;
    static_assert(std::is_same<C1 &, T>::value, "");
    static_assert(std::is_same<C1 &, decltype(x)>::value, "");
}

template<typename T>
void g2(T &&x) {
    std::cout << "type T : " << boost::typeindex::type_id_with_cvr<T>() << std::endl;
    static_assert(std::is_same<C1, T>::value, "");
    static_assert(std::is_same<C1&&, decltype(x)>::value, "");
}

int main() {
    C1 c1{};
    g1(c1);
    g2(C1{});
}
