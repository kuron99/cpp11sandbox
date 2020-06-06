// aligned alloc gives aligned allocated region, requiring deallocated by std::free

#include<cstdlib>
#include<cstring>
#include<iostream>

int main() {
    void*p = std::aligned_alloc(128, 16);
    std::cout << std::hex << p << std::endl;
    std::memset(p, 0, 16);
    std::free(p);
}