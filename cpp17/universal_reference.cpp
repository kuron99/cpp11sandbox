//

#include <iostream>
#include <cassert>

//template <class F, class ...Args>
//auto create_body(F&& f, Args&&...args) {
//    return [&]() {
//        return f(std::forward<Args>(args)...);
//    };
//}

//template <class F, class ...Args>
//auto create_body(F&& f, Args...args) {
//    return [=]() {
//        return f(args...);
//    };
//}

template <class F, class Arg>
auto create_body(F&& f, Arg&& arg) {
    return [f, arg2 = std::forward<Arg>(arg)]() {
        return f(arg2);
    };
}

class MoveOnly {
public:
    int x_{};

    MoveOnly(int x) : x_(x) {}

    MoveOnly() = default;
    ~MoveOnly() = default;
    MoveOnly(MoveOnly const& other) = delete;
    MoveOnly& operator=(MoveOnly const& other) = delete;
    MoveOnly(MoveOnly&& other) noexcept : x_(other.x_ + 1) {}
    MoveOnly& operator=(MoveOnly&& other) noexcept {
        x_ = other.x_ + 1;
        return *this;
    }

};
int main() {
//    {
//        auto f = create_body([](int x) { return x; }, 2);
//        std::cout << "f() : " << f();
//    }
    {
        auto f = create_body([](MoveOnly & x) { return x.x_; }, MoveOnly{2});
        std::cout << "f() : " << f();
    }
}