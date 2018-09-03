#include <type_traits>
#include <tuple>

int main() {
    auto tuple = std::make_tuple(1, 'a', "Hello");
    static_assert(std::is_same<decltype(tuple), std::tuple<int, char, char const*>>::value, "");

    int a = 2;
    char c = 'b';
    char pchr[6] = "World";
    auto refs = std::make_tuple(std::ref(a), std::ref(c), std::ref(pchr));
    static_assert(std::is_same<decltype(refs), std::tuple<int&, char&, char(&)[6]>>::value, "");

    refs = tuple;

}