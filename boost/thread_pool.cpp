#include <iostream>

#include "thread_pool.h"

void f() {
    std::cout << "th: " << std::this_thread::get_id() << std::endl;
}
int main() {
    ThreadPool pool{1};
    pool.submit(f);
    pool.submit(f);
    pool.submit(f);
    pool.submit(f);
    std::this_thread::sleep_for(std::chrono::operator""s(1));
}
