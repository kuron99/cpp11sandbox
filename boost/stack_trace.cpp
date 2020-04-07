#include <iostream>
#include <boost/stacktrace/stacktrace.hpp>

#include <boost/exception/all.hpp>
#include <glog/logging.h>

typedef boost::error_info<struct tag_stacktrace, boost::stacktrace::stacktrace> traced;

template <class E>
inline void throw_with_trace(const E& e) {
    throw boost::enable_error_info(e)
            << traced(boost::stacktrace::stacktrace());
}

class C1 {
public:
    int f1() {
        throw_with_trace(std::domain_error("thrown domain error"));
//        std::cout << boost::stacktrace::stacktrace() << std::endl;
//std::abort();
        return 0;
    }
    int f2() {
        return f1();
    }
    int f3() {
        return f2();
    }
};

int main() {
    ::google::InitGoogleLogging("test");
    ::google::InstallFailureSignalHandler();
    try {
        C1 c;
        c.f3();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        const boost::stacktrace::stacktrace* st = boost::get_error_info<traced>(e);
        if (st) {
            std::cerr << *st << '\n';
        }
    }
}