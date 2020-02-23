// C++11 defines (-x % m) same as -(x % m).
// while floating pointer remainder has variations - fmod same as % and std::remainder rounds quotient to even

#include <cassert>
#include <cmath>

int main() {
    assert(-3 / 2 == -1);
    assert(-3 % 2 == -1);
    assert(-3.0 / 2 == -1.5);
    assert(std::fmod(-3.0, 2.0) == -1.0);
    assert(std::fmod(-5.0, 2.0) == -1.0);
    assert(std::remainder(-3.0, 2.0) == 1.0);
    assert(std::remainder(-5.0, 2.0) == -1.0);

    assert(std::remainder(3.0, 2.0) == -1.0); // not only negative, but also positive generates negative remainder
    assert(std::remainder(5.0, 2.0) == 1.0);
    assert(std::fmod(3.0, 2.0) == 1.0);
    assert(std::fmod(5.0, 2.0) == 1.0);
}