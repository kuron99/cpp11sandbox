// check spaceship operator work

//#include "compare"
#include "cassert"

class C1 {
public:
    C1(int x) : x_(x) {}

    int operator<=>(C1 const& other) {
        return x_ - other.x_;
    }
    bool operator<(C1 const& other) {
        return x_ < other.x_;
    }
private:
    int x_{};
};

int main() {

    C1 c1{1};
    C1 c2{2};
    assert(c1 <=> c2 < 0);
    assert(c1 < c2);
}