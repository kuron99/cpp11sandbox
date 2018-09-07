#include <iostream>

class C1 {};
int main() {
    C1 c1{};
    auto n1 = c1;
    static_assert(std::is_same<decltype(c1), C1>::value, "");
    auto n2{c1};
    static_assert(std::is_same<decltype(n2), C1>::value, "");
    auto pc1 = &c1;
    static_assert(std::is_same<decltype(pc1), C1*>::value, "");
    
    const C1 cc1{};
    static_assert(std::is_same<decltype(cc1), const C1>::value, "");
    auto pcc1 = &cc1;
    static_assert(std::is_same<decltype(pcc1), const C1*>::value, "");
    auto &rcc1 = cc1;
    static_assert(std::is_same<decltype(rcc1), const C1&>::value, "");

}
