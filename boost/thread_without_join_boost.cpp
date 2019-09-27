// boost::thread automatically detach on destruction in boost thread version 2
#include "boost/thread.hpp"

void f() {

}
int main() {
    boost::thread th{f};
}