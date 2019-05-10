#include <any>
#include <cassert>

class Base {
public:
    virtual ~Base() = default;
    int x_{1};
};

class C1 : public Base {
public:
    C1() noexcept = default;
    ~C1() noexcept = default;
    C1(C1 const& other) = default;
    C1(C1&& other) noexcept = default;
    C1& operator=(C1 const& other) = default;
    C1& operator=(C1&& other) noexcept = default;
    int y_{2};
};

int main() {
    std::any a = 1;
    // std::any::type() requires RTTI
//    a.type();

    C1* c1 = new C1();
    Base* b = c1;
    // dynamic_cast requires RTTI
    //auto casted = dynamic_cast<C1*>(b);

    a = b;
    bool caught = false;
    try {
        std::any_cast<C1*>(a);
    } catch (std::bad_any_cast& e) {
        caught = true;
    }
    assert(caught);
    auto a2 = std::any_cast<Base*>(a);
    auto casted = reinterpret_cast<C1*>(a2);
    assert(casted->y_ == 2);
    delete c1;
    return 0;
}