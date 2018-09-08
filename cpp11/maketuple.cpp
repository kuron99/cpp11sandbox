// auto for make_tuple elements are somewhat vague - const C1 becomes C1

#include <type_traits>
#include <tuple>

class C1 {

};
int main() {
    auto tuple = std::make_tuple(1, 'a', "Hello");
    static_assert(std::is_same<decltype(tuple), std::tuple<int, char, char const*>>::value, "");

    C1 c1{};
    const C1 cc1{};
    auto tuple2 = std::make_tuple(c1, &c1, cc1, &cc1);
    static_assert(std::is_same<decltype(tuple2), std::tuple<C1, C1*, C1, const C1*>>::value, ""); // cc1 -> not const C1

    int a = 2;
    char c = 'b';
    char arr[6] = "World";
    const char* pchr = arr;
    auto refs = std::make_tuple(std::ref(a), std::ref(c), std::ref(pchr));
    static_assert(std::is_same<decltype(refs), std::tuple<int&, char&, const char*&>>::value, "");
    refs = tuple;

}