#include <iostream>
#include <mutex>
#include <future>

#include "thread_pool.h"

using namespace std::chrono_literals;

void freeze() {
    std::cout << "th: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(1h);
}
void f() {
    std::cout << "th: " << std::this_thread::get_id() << std::endl;
}
int main() {
    ThreadPool pool{3};
    std::packaged_task<int(void)> task{[]() {
        std::cout << "packaged task " << std::endl;
        return 1;
    }};
//    task();
    auto future = task.get_future();
    pool.submit(task);
    pool.submit(std::ref(task));
    std::this_thread::sleep_for(1s);
    std::cout << future.get() << std::endl;
    pool.submit(f);
//    pool.submit(f);
//    pool.submit(f);
}
