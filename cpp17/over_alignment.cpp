// gcc allows very large over alignment

#include <cstddef>
#include <iostream>

int main() {
    static_assert(alignof(std::max_align_t) == 16);
    alignas(65536) struct S { int c1; } s1;

    std::cout << std::hex << &s1 << std::endl;

}