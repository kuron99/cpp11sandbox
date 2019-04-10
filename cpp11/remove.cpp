// verify tricky behavior of std::remove - it leaves removed element at the end of the container
// so usually erase() should be called to shrink the container dropping the removing ones at the end

#include <cassert>
#include "vector"
#include "algorithm"
#include "iostream"

int main() {
    std::vector<int> v1 {1,2,3,4,5};
    assert(5 == v1.size());

    auto itr = std::remove_if(v1.begin(), v1.end(), [](int x) { return x%2 == 0;});
    assert(5 == v1.size());
    assert(1 == v1[0]);
    assert(3 == v1[1]);
    assert(5 == v1[2]);
    assert(3 == std::distance(std::begin(v1), itr));

    v1.erase(itr, v1.end());
    assert(3 == v1.size());
}