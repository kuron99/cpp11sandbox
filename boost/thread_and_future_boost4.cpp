// boost::thread automatically detach on destruction in boost thread version 2
#include "boost/thread.hpp"
#include "boost/asio.hpp"

void f() {

}
int main() {
    boost::thread th{f};
    auto fut = boost::async(boost::launch::async, []() {

    });
//    fut.then(boost::launch::async, [](){});
    boost::asio::
}