// std::any remembers value type and throws exception on cast if error
// When insert to any, valus is always copied, while when casting, you can copy or get the reference to the value stored in any.

#include <any>
#include <iostream>
#include <memory>
#include <cassert>

using namespace std::literals::string_literals;

class C1 {
public:
    C1() noexcept : C1{0} {}
    ~C1() noexcept = default;
    C1(const C1& other) : C1{1} {}
    C1(C1&& other) : C1{2} {}
    C1& operator=(const C1& other) { x_ = 3; return *this; };
    C1& operator=(C1&& other) noexcept { x_ = 4; return *this; };
    C1(int x) : x_(x) {}
    int f1() {
        return x_;
    }
private:
    int x_;
};

int main() {
    std::any a1;
    int32_t a = 1;
    a1 = a;
    assert(std::any_cast<int>(a1) == 1);
    assert(std::any_cast<int32_t>(a1) == 1);
    assert(&std::any_cast<int32_t&>(a1) != &a);  // value is copied
    a1 = 2U;
    assert(std::any_cast<uint32_t>(a1) == 2U);
    char* str = "ABC";
    a1 = str;
    assert(std::any_cast<char*>(a1) == str);
    a1 = "XYZ"s;
    assert(std::any_cast<std::string>(a1) == "XYZ"s);

    std::any a2 = "XYZ"s;
    assert(std::any_cast<std::string>(a1) == std::any_cast<std::string>(a2));

    C1 c1{9};
    a1 = c1;  // copied
    assert(c1.f1() == 9);
    assert(std::any_cast<C1>(a1).f1() == 1);
    a1 = &c1;
    assert(std::any_cast<C1*>(a1)->f1() == 9);

    C1 to_move{10};
    a1 = std::move(to_move);
    assert(std::any_cast<C1>(a1).f1() == 1);  // this is still copied
    a1.emplace<C1>(std::move(to_move));
    assert(std::any_cast<C1>(a1).f1() == 1);  // this is still copied

    // read as reference
    C1 c2{22};
    a1 = c2;
    C1 & rc2_1 = std::any_cast<C1&>(a1);
    C1 & rc2_2 = std::any_cast<C1&>(a1);
    assert(&rc2_1 == &rc2_2);

    // between any, you can copy or move
    C1 c3{33};
    a1 = c3;
    std::any a3 = std::any(a1);
    assert(&std::any_cast<C1&>(a1) != &std::any_cast<C1&>(a3)); // copied, address are different

    auto ptr = &std::any_cast<C1&>(a1);
    a3 = std::move(a1);
    assert(&std::any_cast<C1&>(a3) == ptr); // moved, address are same

}

