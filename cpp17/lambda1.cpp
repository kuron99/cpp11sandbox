// lambda cannot change the variable captured by copy, unless the lambda is mutable
// size of lamda is determined by the caputured variables
#include <cstdint>
#include <cassert>

int main() {
    {
        int c = 3;
        auto f = [c]() {
//        ++c;
            return c;
        };
        int x = f();
        assert(x == 4);

        auto f2 = f;
        assert(f2() == 5);

        static_assert(sizeof(f) == 4);
    }
    {
        std::int64_t c = 3;
        auto f = [c]() mutable {
            ++c;
            return c;
        };
        assert(f() == 4);
        static_assert(sizeof(f) == 8);
    }
    {
        int c = 3;
        auto f = [&c]() mutable {
            ++c;
            return c;
        };
        assert(f() == 4);
        static_assert(sizeof(f) == 8);
    }
}