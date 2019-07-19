// unsigned needs care - underflow easily happens

#include <cassert>
#include <cinttypes>

int main() {
    std::size_t a{1}, b{0};
    std::size_t n{0};
    assert( n - a > b);
}
