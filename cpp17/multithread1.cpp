// launch::deferred runs the task on the same thread, when future::get() is called
// while launch::async starts new thread. Default is async.

#include <future>
#include <cassert>

int main() {
    auto tid = std::this_thread::get_id();
    {
        std::thread::id tid2{};
        auto future = std::async(std::launch::deferred, [&tid2]() {
            tid2 = std::this_thread::get_id();
        });
        assert(tid != tid2);
        future.get();
        assert(tid == tid2);
    }
    {
        auto tid2 = std::this_thread::get_id();
        std::async(std::launch::async, [&tid2]() {
            tid2 = std::this_thread::get_id();
        });
        assert(tid != tid2);
    }
    {
        auto tid2 = std::this_thread::get_id();
        std::async([&tid2]() {
            tid2 = std::this_thread::get_id();
        });
        assert(tid != tid2);
    }
}