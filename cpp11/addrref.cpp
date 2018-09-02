// what is address of rvalue reference
// -> rvalue ref. is lvalue, and it holds address

#include <cassert>
class C1 {

};
int main() {
    C1 c1{};
    C1& rc1 = c1;
    assert(&rc1 == &c1);

    C1&& rrc1 = C1{};
    C1& rc2 = rrc1;
    assert(&rrc1 == &rc2);

    C1& rc3 = static_cast<C1&>(rrc1);
    assert(&rc2 == &rc3);

    const C1&& crrc1 = C1{};
    const C1& rc4 = crrc1;
    assert(&crrc1 == &rc4);
}
