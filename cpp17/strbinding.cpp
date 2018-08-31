#include <iostream>
#include <cassert>
#include <tuple>

class C1 {

};

int main() {
    int x = 10;
    double y = 20.0;
    std::tuple<int, double, C1*> tuple = std::make_tuple(x, y, new C1);

    auto [a, b, c] = tuple;

    static_assert(std::is_same_v<decltype(a), int>);
    static_assert(std::is_same_v<decltype(b), double>);
    static_assert(std::is_same_v<decltype(c), C1*>);

    delete c;
}
