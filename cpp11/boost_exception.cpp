#include <exception>
#include <iostream>
#include "boost/exception/all.hpp"
#include "boost/stacktrace.hpp"

class Exception : public std::exception, boost::exception {

};

int f1() {
    std::cout << boost::stacktrace::stacktrace() << std::endl;
   throw Exception();
}

int f2() {
    f1();
}

int main() {
    try {
        f1();
    } catch (Exception& ex) {
        std::cout << ex.what() << std::endl;
    }

}
