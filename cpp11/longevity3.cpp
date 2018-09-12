// temp object passed to initialize list is ill-formed since C++14
// this comples fine on C++11, but sanitizer complaints temp not prolonged after the constructor

#include <string>
#include <iostream>

class C1 {
public:
    template <typename T>
    C1(T&& s) : s_(std::forward<T>(s)) {
        std::cout << "C1(C1&&)" << std::endl;
    }
    const std::string& s() const {
        return s_;
    }
private:
    std::string&& s_;
};

int main() {
    C1 c1("xxx");
    std::cout << c1.s() << std::endl;
}

