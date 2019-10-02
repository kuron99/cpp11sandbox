#include <map>
#include <cassert>
using namespace std;
using namespace std::string_literals;

class C1 {
public:
    C1() {
        ++counter_;
    };
    C1(int x) : x_(x) {
        ++counter_;
    }
    ~C1() {
        --counter_;
    }
    int x_{};
    static int counter_;
};
int C1::counter_ = 0;

int main() {
    map<string, C1> map{};
    map["A"s].x_ = 1;
    map["B"s].x_ = 2;
    assert(2 ==  C1::counter_);

    assert(2 ==  map.size());
    {
        auto node = map.extract("A"s);
        assert("A"s == node.key());
        assert(1 == node.mapped().x_);
        assert(1 ==  map.size()); // after extract(), the element is removed from the map
        assert(2 ==  C1::counter_);
    }
    assert(1 ==  map.size()); // after destruction of node handle, the element is gone
    assert(1 ==  C1::counter_);
}