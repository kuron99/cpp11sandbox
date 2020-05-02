// construct from narrowing conversion prohibited with {}
#include <cstdint>

int main() {
    std::int32_t x = 1;
    std::int64_t y{x};
    std::int32_t z{y};
}