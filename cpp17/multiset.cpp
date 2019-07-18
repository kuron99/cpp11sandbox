// multiset size() returns the number of elements counted with multiplicity
// iterators repeatedly visit the same value

#include <set>
#include <cassert>
#include <iostream>
#include <algorithm>

int main() {
    std::multiset<int> ms{1,2,3,3,4};
    assert(ms.size() == 5);
    assert(ms.count(1) == 1);
    assert(ms.count(3) == 2);
    assert(ms.count(5) == 0);

    auto itr = ms.begin();
    ++itr;
    ++itr;
    assert(*itr == 3);
    ++itr;
    assert(*itr == 3);

    int count = 0;
    std::for_each(ms.begin(), ms.end(), [&count](auto const& x) {
        ++count;
        std::cout << x << std::endl;
    });
    assert(count == 5);

    std::set<int> s{};
    std::copy(ms.begin(), ms.end(), std::inserter(s, s.begin()));
    assert(s.size() == 4);
}
