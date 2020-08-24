// gcc allows very large over alignment

#include <cstddef>
#include <cassert>
#include <iostream>
#include <vector>

class alignas(65536) C1 {
    int x;
};

class C2 {
    int x;
};

int main() {
    static_assert(alignof(std::max_align_t) == 16);
    C1 c;
    std::cout << std::hex << &c << std::endl;
    assert((std::ptrdiff_t (&c) & 65535UL) == 0);

    std::vector<C1> v(2);
    assert((std::ptrdiff_t (&v[0]) & 65535UL) == 0);
    assert((std::ptrdiff_t (&v[1]) & 65535UL) == 0);



}