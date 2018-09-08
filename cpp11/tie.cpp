// std::tie returns a tuple with reference
// you can omit template parameter for std::tie

#include <type_traits>
#include <tuple>
#include <cassert>

class C1 {

};

int main() {
    auto tuple = std::make_tuple(1, 'a', "Hello");
    static_assert(std::is_same<decltype(tuple), std::tuple<int, char, char const *>>::value, "");

    int a;
    char b;
    const char *c = "World";
    std::tie<int, char, const char *>(a, b, c) = tuple;
    std::tie(a, b, c) = tuple;
    assert(a == 1);
    assert(b == 'a');
    assert(memcmp(c, "Hello", 5) == 0);

    b = 'b';
    a = 2;
    std::tie(a, std::ignore, c) = tuple;
    assert(a == 1);
    assert(b == 'b');

    C1 c1{};
    int a1 = 1;
    char b1 = 'b';
    int a2 = 2;
    char b2 = 'B';
    std::tuple<int &, char &> tie = std::tie(a1, b1);
    std::tuple<int &, char &> tie2 = std::tie(a2, b2);
    tie = tie2;
    assert(a1 == 2);
    assert(b1 == 'B');
}
