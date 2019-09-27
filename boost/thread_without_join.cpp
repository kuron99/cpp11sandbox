#include <thread>
#include "boost/thread.hpp"

void f() {

}
int main() {
    boost::thread th{f};
//    std::thread th2{f};
}