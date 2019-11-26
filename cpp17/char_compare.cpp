#include <cstring>
#include <string>
#include <cassert>
int main() {
    char c1{'A'};
    char c2{'\xEF'};
    assert(c1 > c2);
    assert(std::memcmp(&c1, &c2, 1) < 0);
    std::string s1{c1};
    std::string s2{c2};
    assert(s1 < s2);
}