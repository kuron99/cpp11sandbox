#include <iostream>
#include <mutex>
#include <future>
#include <cassert>

#include "thread_pool.h"

using namespace std::chrono_literals;

void f() {
    std::cout << "th: " << std::this_thread::get_id() << std::endl;
}
int main() {
    ThreadPool pool{3};
    std::packaged_task<int(void)> task{[]() {
        std::cout << "packaged task " << std::endl;
        return 1;
    }};
    auto future = task.get_future();
    pool.submit(std::ref(task));
    std::this_thread::sleep_for(1s);
    assert(1 == future.get());
    pool.submit(f);
}
