// ostringstream can share buffer with ostream
// Don't forget to specify ios_base::ate to avoid overwriting buffer

#include <iostream>
#include <sstream>
#include <cstring>
#include <cassert>

using namespace std;
using namespace std::string_literals;

int main() {
//    ostringstream oss{"000"s, ios_base::ate};
    ostringstream oss{"000"s};
    ostream os{oss.rdbuf()};

    oss << "ABC";
    os << "XYZ";

    assert("ABCXYZ" == oss.str());
}