// TBB concurrent queue is now lock free, while concurrent bounded queue pop() blocks until present

#include <thread>
#include "tbb/concurrent_queue.h"

int main() {
    tbb::concurrent_queue<int> cq{};
    tbb::concurrent_bounded_queue<int> cbq{};

    int a;
    cbq.try_pop(a);
    cbq.pop(a);
}
