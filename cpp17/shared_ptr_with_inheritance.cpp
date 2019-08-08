// shared ptr works well with inheritance
#include <cassert>
#include <memory>

class C1 {
public:
    virtual int f() {
        return 1;
    }

};

class C2 : public C1 {
public:
    int f() override {
        return 2;
    }
};

class Owner {
    std::shared_ptr<C1> c1_{};
public:
    Owner(std::shared_ptr<C2> derived) : c1_(derived) {}  // shared_ptr<C1> can be initialized by shared_ptr<C2>
    int f() {
        return c1_->f();
    }
};

int main() {
    auto c2 = std::make_shared<C2>();
    Owner o1{c2};
    assert(2 == c2->f());
}
