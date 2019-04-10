// verify moving vector element

#include <iostream>
#include <vector>
#include <cassert>

class C1 {
public:
    ~C1() noexcept = default;
    C1(C1 const& other) = delete;
    C1(C1&& other) noexcept : x_(100) {
//        other.x_ = 1000;
    }
    C1& operator=(C1 const& other) = delete;
    C1& operator=(C1&& other) noexcept = default;

    C1() : x_(0) {};
    C1(int x) : x_(x) {};
    int x_{};
};
C1 f1(std::vector<C1>& v, int i) {
    return std::move(v[i]);
}
int main() {
    std::vector<C1> v{};
    v.emplace_back(1);
    v.emplace_back(1);
    v.emplace_back(1);
    v.emplace_back(1);

    auto ret1 = f1(v,0);
    auto ret2 = f1(v,1);
    auto ret3 = f1(v,2);
    auto ret4 = f1(v,2);

    assert(400 == ret1.x_ + ret2.x_ + ret3.x_ + ret4.x_ );

    // You should not touch variables after moved
    // following behaves randomly... some are 100 and some are 1
//    std::cout << v[0].x_ << std::endl;
//    std::cout << v[1].x_ << std::endl;
//    std::cout << v[2].x_ << std::endl;
//    std::cout << v[3].x_ << std::endl;

//    C1 x1(std::move(v[0]));
//    C1 x2(std::move(v[1]));
//    C1 x3(std::move(v[2]));
//    std::cout << "sum: " << x1.x_+x2.x_+x3.x_ << std::endl;
//    std::cout << v[0].x_ << std::endl;
//    std::cout << v[1].x_ << std::endl;
//    std::cout << v[2].x_ << std::endl;

    return 0;
}

