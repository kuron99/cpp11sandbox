
#include <chrono>

class watch {
public:
    using clock = std::chrono::high_resolution_clock;

    watch() {
        begin_ = clock::now();
    }

    long long stop() {
        const std::chrono::time_point<clock> end = clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(end - begin_).count();
    }

    void reset() {
        begin_ = clock::now();
    }

private:
    std::chrono::time_point<clock> begin_;
};
