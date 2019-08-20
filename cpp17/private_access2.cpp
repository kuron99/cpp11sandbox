// private membmer variable can be accessed when public template function exists

#include <iostream>

struct A
{
    A() : x("proof!") {}
    template<typename T>
    void f1();

private:
    char const* x;
};

struct B {};

static const char* peeked{};

template<>
void A::f1<B>() {
    peeked = this->x;
}

int main()
{
    A a;
    a.f1<B>();
    std::cout << peeked << std::endl;
};
