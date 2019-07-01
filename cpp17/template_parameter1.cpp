// playing around template template parameters
// template template parameter allow providing child parameter separately

#include <vector>

class C0 {

};
template <int N>
class C1 {
public:
    char buf[N];
};

template <template<int N> typename C, int M>
class C2 : public C<M> {
};

template <template<int N = 10> typename C, int M>
class C3 {
    std::vector<C<M>> vector_{};
public:
    template<typename T>
    void add(T c) {
        vector_.emplace_back(c);
    }
};

// you can parameterize a type by using
template <int N>
using CX = C0;

template<template<class, class> class Vector, class T, class Alloc = std::allocator<T>>
class C4 {
    Vector<T, Alloc> v;
};

int main() {
    // C1's parameter can be passed as one for C2
    static_assert(sizeof(C2<C1, 5>) == 5);
    static_assert(sizeof(C2<C1, 10>) == 10);

    C1<5> c1{};
    C3<C1, 5> test;
    C3<CX, 5> test2;
    test.add(c1);
    C4<std::vector, C0, std::allocator<C0>> c4;
    C4<std::vector, C0> c4_2{};

    return 0;
}
