// promise/future are channel between threads
#include <future>
#include <thread>
#include <cassert>

int main() {

    std::promise<int> p_to_main{}, p_to_thread{};
    auto fut_to_main = p_to_main.get_future();
    auto fut_to_thread = p_to_thread.get_future();
    auto fut = std::async(std::launch::async, [&p_to_main, &fut_to_thread]() {
        p_to_main.set_value(100);
        auto r = fut_to_thread.get();
        assert(r == 300);
        return 1;
    });

    p_to_thread.set_value(300);
    auto out2 = fut_to_main.get();
    assert(out2 == 100);

    auto out = fut.get();
    assert(out == 1);
    std::future<int> receive{};
    {
        std::promise<int> dummy{};
        receive = dummy.get_future();
    }
    bool caught = false;
    try {
        receive.get();
    } catch (std::future_error& e) {
        caught = true;
        assert(e.code().value() == static_cast<int>(std::future_errc::broken_promise));
    }
    assert(caught);
}
