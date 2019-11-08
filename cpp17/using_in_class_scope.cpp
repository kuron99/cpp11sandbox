// compiler error with "using C1 = C1<T>" in class scope
// it's ok if you use ::C1<T>

#include <cassert>

template<typename T>
struct C1 {
    T operator()() const {
        return T(1);
    }
};

template<typename T>
struct C2 {
//    using C1 = C1<T>;  // compiler error !!!
    using C1 = ::C1<T>;
    C1 f() {
        return C1();
    }
};
int main() {
    C2<int> c2int{};
    assert(1 == (c2int.f())());
}