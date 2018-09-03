#include <utility>
#include <memory>
#include <iostream>

class C1 {

};

template <typename T>
void func1(T&& x) {
    std::cout << "func1(T&&)" << std::endl;
}

void func1(std::unique_ptr<C1> ptr) {
    std::cout << "func1(unique_ptr)" << std::endl;
}
int main() {
    C1 c1{};
    std::unique_ptr<C1> ptr{new C1};

    func1(c1);
    func1(std::move(ptr));

}
