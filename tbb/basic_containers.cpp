// TBB concurrent queue is now lock free, while concurrent bounded queue pop() blocks until present

#include <thread>
#include "tbb/concurrent_queue.h"
#include "tbb/concurrent_priority_queue.h"

int main() {
    tbb::concurrent_queue<int> cq{};
    tbb::concurrent_bounded_queue<int> cbq{};

    tbb::concurrent_priority_queue<int> cpq{};
    int a;
    cbq.try_pop(a);
    cbq.pop(a);
}
