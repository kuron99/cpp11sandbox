#include <vector>
#include <string>
#include <cassert>

int main() {
    std::vector<std::string> v{};
    assert(v.capacity() == 0);

    v.emplace_back("A");
    assert(v.capacity() == 1);

    v.emplace_back("B");
    assert(v.capacity() == 2);

    v.emplace_back("C");
    assert(v.capacity() == 4);
}