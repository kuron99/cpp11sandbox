// boost::future has then() method

#include <cassert>
#include "boost/thread.hpp"
#include "boost/asio.hpp"
#include "boost/thread/future.hpp"

void f() {

}

int main() {
    auto fut = boost::async(boost::launch::async, []() -> int {
        return 1;
    });
    auto f2 = fut.then([](boost::future<int> x) -> int {
        return x.get();
    });
    assert(1 == f2.get());
}