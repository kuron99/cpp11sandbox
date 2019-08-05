// didn't know const function can update the argument value via reference

#include <cassert>
class C1 {
    int x_{};
public:
    C1(int x) : x_(x) {}

    void get_x(int &x) const {
        x = x_;
    }
};
int main() {
    C1 c1{2};
    int x{};
    c1.get_x(x);
    assert(x == 2);
}