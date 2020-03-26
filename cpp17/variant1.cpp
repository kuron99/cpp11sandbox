// std::variant has type info. and its size is greater than union

#include <variant>
#include <cstdint>
#include <iostream>

#include <boost/type_index.hpp>


struct C0 {
    std::variant<std::int64_t> x_;
};

struct C1 {
    std::variant<std::int64_t, double> x_;
};

struct C2 {
    std::variant<std::int64_t, std::int32_t, float, double, short> x_;
};

int main() {
    // even only std::int64_t, variant has type info and the size is 16
    static_assert(sizeof(C0) == 16);
    static_assert(sizeof(std::variant<std::int64_t>) == 16);
    static_assert(sizeof(C1) == 16);
    static_assert(sizeof(C2) == 16);

    C2 v;
    v.x_ = 1;

    std::cout << boost::typeindex::type_id_with_cvr<decltype(std::get<0>(v.x_))>() << std::endl; // shows "long&"
    std::cout << boost::typeindex::type_id_with_cvr<decltype(std::get<float>(v.x_))>() << std::endl; // shows "float&"
}