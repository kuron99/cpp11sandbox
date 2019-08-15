// what is std::decimal in g++?

#include <decimal/decimal>

int main() {
//    auto a = std::make_decimal128();
    static_assert(sizeof(std::decimal::decimal32) == 4);
    static_assert(sizeof(std::decimal::decimal64) == 8);
    static_assert(sizeof(std::decimal::decimal128) == 16);
}