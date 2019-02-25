// function wrapper supporting lambda

#include <functional>
#include <cassert>

template <typename >
class Wrapper;

template <typename R, typename... T>
class Wrapper<R(T...)> {
public:
    using func_type = std::function<R(T...)>;
    Wrapper(func_type f) : f_(f) {}

    R operator()(T&&... args) {
        R result = f_(std::forward(args)...);
        return result;
    }

private:
    func_type f_;
};

int main() {
    int x = 0;
    Wrapper<int()> wrapped([&x] () { return ++x; });
    wrapped();
    assert(x == 1);
}
