// you need to open stringstream with ios_base::ate flag to append

#include <iostream>
#include <sstream>
#include <cassert>

int main() {
    std::stringstream ss{"ABC"};
    ss << "DDD";
    assert(ss.str() == "DDD");

    std::stringstream ss2{"ABC", std::ios_base::in|std::ios_base::out|std::ios_base::ate};
    ss2 << "DDD";
    assert(ss2.str() == "ABCDDD");
}