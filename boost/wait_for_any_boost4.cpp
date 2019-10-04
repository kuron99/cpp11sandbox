// boost::thread automatically detach on destruction in boost thread version 2
#include <thread>
#include "boost/thread.hpp"
#include "boost/asio.hpp"

using namespace std::chrono_literals;
void f() {

}
int main() {
//    boost::thread th{f};
    auto fut = boost::async(boost::launch::async, []() {
        std::this_thread::sleep_for(1s);
    });
    auto fut2 = boost::async(boost::launch::async, []() {
        std::this_thread::sleep_for(1s);
    });
    std::vector<boost::future<void>> v_{};
    v_.emplace_back(std::move(fut));
    v_.emplace_back(std::move(fut2));
    boost::wait_for_any(v_.begin(), v_.end());
}