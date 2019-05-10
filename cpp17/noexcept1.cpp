// you can use noexcept() operator to know if given operation raises exception
// special generated functions ctor/dtor are noexcept by default unless base/member are potentially throwing on init

#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <any>
#include <bits/unique_ptr.h>

class C1 {
public:
    C1() = default;
    ~C1() = default;
    C1(C1 const& other) = default;
    C1(C1&& other) = default;
    C1& operator=(C1 const& other) = default;
    C1& operator=(C1&& other) = default;
    C1(int x) {}
    std::map<std::string, std::string> map_{};
    std::shared_ptr<C1> model_{};
    std::vector<std::any> values_{};
    static std::shared_ptr<C1> EMPTY_MODEL;
};

void function_throws() {

}
void function_noexcept() noexcept {

}

void function_throws_with_noexcept() noexcept {
    throw std::exception();
}

class C2 {
public:
    C2() = default;

private:
    C1 c1{1};
};

int main() {
    static_assert(noexcept(std::map<int, int>()));
    static_assert(std::is_nothrow_move_constructible<C1>());

    static_assert(!noexcept(std::make_unique<C1>()));
    static_assert(!noexcept(new C1));  // can throw bad alloc
    static_assert(!noexcept(new C2));  // can throw bad alloc

    // generated special function is noexcept if base/member doesn't throw on init
    static_assert(noexcept(C1()));
    static_assert(!noexcept(C1(1)));
    static_assert(!noexcept(C2()));

    static_assert(!noexcept(function_throws()));
    static_assert(noexcept(function_noexcept()));
    static_assert(noexcept(function_throws_with_noexcept()));

    return 0;
}

