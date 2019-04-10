// simplest sample for add_pointer

#include<type_traits>
#include <iostream>
#include <cassert>

#include "boost/type_index.hpp"
template <typename T>
class TC1 {

};

class C1 {};

int main() {
    C1 c1;
    std::add_pointer_t<C1> c1p;

    std::cout << "decltype<c1p>: " << boost::typeindex::type_id_with_cvr<decltype(c1p)>() << std::endl;
    static_assert(std::is_pointer_v<decltype(c1p)>);
}