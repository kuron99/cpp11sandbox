// emplace_bakc return reference, which becomes invalid on relocation

#include <vector>
#include <memory>
#include <iostream>

class C1 {
public:
    C1(int x) : x_(x) {}
    int x_;
    int x() {return x_;}
};
int main() {
    std::vector<std::unique_ptr<C1>> vec{};
    auto& ref = vec.emplace_back(std::make_unique<C1>(100));
    auto& ref2 = vec.emplace_back(std::make_unique<C1>(100));  // relocation happens here
    std::cout << ref->x() << std::endl; // invalid access
}