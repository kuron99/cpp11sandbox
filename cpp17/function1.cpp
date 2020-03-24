// you need & to the return type of lambda in order to return reference (which is not automatically inferred)

#include <functional>
int main() {
    int x;
    std::function<int&(void)> aaa = [&]() -> int& { return x;};
//    std::function<int&(void)> bbb = [&]() { return x;};  // error!
}