// std::less can be called like this

#include <functional>
#include <cassert>

int main() {
    int x = 0;
    int y = 1;
    assert(std::less<int>{}(x, y));
}
