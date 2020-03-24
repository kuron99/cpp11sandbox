// hard to make class trivially constructible

#include <type_traits>
#include <memory>

class C1 {

};

class C2 {
public:
    C2() = default;
    int x_;
    double y_;
};

class C3 {
public:
    C3() {}; // user defined constructor is not trivial
};

class C4 {
public:
    C4() = default;
    int x_{}; // initializing member is not trivial
};

class C5 {
public:
    C5() = default;
    std::shared_ptr<int> x_; // member with non-trivial constructor makes C5 non-trivially constructible
};

class C6 {
public:
    C6() = default;
    std::array<int, 5> x_; // member with trivial constructor makes C6 trivially constructible
};

int main() {
    static_assert(std::is_trivially_constructible_v<C1>);
    static_assert(std::is_trivially_default_constructible_v<C1>);
    static_assert(std::is_trivially_default_constructible_v<C2>);
    static_assert(!std::is_trivially_default_constructible_v<C3>);
    static_assert(!std::is_trivially_default_constructible_v<C4>);
    static_assert(!std::is_trivially_default_constructible_v<C5>);
    static_assert(std::is_trivially_default_constructible_v<C6>);

    static_assert(!std::is_trivially_constructible_v<std::unique_ptr<int>, int*>);
}