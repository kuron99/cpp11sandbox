// optional can hold values maybe null
// accessing methods & members via nullopt is UB

#include <optional>
#include <iostream>

class C1 {
public:
    C1(int x) : x_(x) {}
    int f1() {
        return x_;
    }
private:
    int x_;
};

int main() {
    C1 c1{-1};
    std::optional<C1> opt{c1};
    std::optional<C1> opt2{std::nullopt};
    if (opt) {
        std::cout << opt->f1() ;
    }
    if (opt2) {
        std::cout << opt2->f1() ;
    }
    // this is invalid, but sanitizer doesn't complain as of now
    std::cout << opt2->f1() ;
}

