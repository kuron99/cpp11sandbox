
#include "tbb/cache_aligned_allocator.h"
#include <new>
int main() {
    tbb::cache_aligned_allocator<char> alloc{};

}