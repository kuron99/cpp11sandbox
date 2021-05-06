// check if atomic<> is trivially copyable

#include<atomic>
#include <iostream>
#include <cassert>

int main() {
    static_assert(std::is_trivially_copyable_v<std::atomic<int>>);
//    std::atomic<int> a = 100;
//    std::atomic<int> aa(a) ;
//    std::atomic<int> aaa(std::move(a)) ;
//
//    std::atomic<int> b = 100;
//    b = a;
//    b = std::move(a);
    void* p = nullptr;
    int x = 0;
    p = &x;

    std::cout << "p = " << p << std::endl;
    return 0;
}