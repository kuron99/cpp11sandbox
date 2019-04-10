// confirm std::function copies the input when constructed

#include <iostream>
#include <functional>
#include <cassert>

struct A {
    int v = 0;
    int operator()() {
        return ++v;
    }
};

int g1(std::function<int()> const& arg) {
    return arg();
}

int main() {
    A a;
    const std::function<int()> f { a }; // f will have a copy of a
    assert(1 == g1(a));
    assert(1 == g1(a)); // A is copied to create std::function on every g1(a) call

    assert(1 == g1(f));
    assert(2 == g1(f));

    assert(1 == a());
    assert(2 == a());
    assert(3 == f());
    assert(4 == f());
}
