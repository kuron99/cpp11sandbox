// function wrapper

#include <functional>

template <typename >
class Wrapper;

template <typename R, typename... T>
class Wrapper<R(T...)> {
public:
    using func_type = std::add_pointer_t<R(T...)>;
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
    Wrapper<int()> wrapped([] () { return 1; });

}
