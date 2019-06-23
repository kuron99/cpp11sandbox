// seed() can rewind the random sequence generated

#include <random>
#include <cassert>

int main() {
    constexpr static int SEED = 1111;
    std::mt19937_64 mt{1111};
    std::vector<std::int64_t> values{};
    for (int i=0; i < 1000; ++i) {
        values.emplace_back(mt());
    }
    mt.seed(SEED);
    for (int i=0; i < 1000; ++i) {
        assert(mt() == values[i]);
    }
}
