// experiment with std::is_same<T, U>

#include <iostream>

class C1 {

};

int main() {
    C1 c1{};
    C1& rc1 = c1;
    C1* pc1 = &c1;
    C1** ppc1 = &pc1;
    C1*& rpc1 = pc1;
    C1&& rrc1 = C1{};
    static_assert(std::is_rvalue_reference<decltype(c1), C1>::value, "true");
    static_assert(std::is_rvalue_reference<decltype(c1), C1>::value, "true");

    const C1 cc1{};
    volatile C1 vc1{};
    const C1 & rcc1 = C1{};
    const C1 && rrcc1 = C1{};
}
