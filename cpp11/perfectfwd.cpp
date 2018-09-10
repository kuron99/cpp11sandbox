// whether unique_ptr is received by universal reference or not
#include <iostream>

class C1 {

};

static int xxx = 0;
template <typename T>
void func1(T&& x) {
    std::cout << "func1(T&&)" << std::endl;
    xxx = 1;
}

void func1(std::unique_ptr<C1> ptr) {
    std::cout << "func1(unique_ptr)" << std::endl;
    xxx = 2;
}
int main() {
    C1 c1{};
    std::unique_ptr<C1> ptr{new C1};

    func1(c1);
    assert(xxx == 1);
    func1(std::move(ptr));
    assert(xxx == 2);
    xxx = 0;
    func1(std::move(c1));
    assert(xxx == 1);
}
