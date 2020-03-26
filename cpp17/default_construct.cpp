#include <cassert>
#include <memory>

class C1 {
public:
    int x_;
    int y_;
};

int main() {
    C1 c{1, 2}; // why this is possible?
    assert(1 == c.x_);
    assert(2 == c.y_);

//    auto p = new C1(1,2);  // error!!
//    auto x = std::make_unique<C1>(1,2); // error!!
}