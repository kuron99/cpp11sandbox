// istringstream can share buffer with istream

#include <iostream>
#include <sstream>
#include <cstring>
#include <cassert>

using namespace std;
using namespace std::string_literals;

int main() {
    istringstream iss{"ABCYZ123"s};
    istream is{iss.rdbuf()};
    string a(3, 0);
    string b(2, 0);
    string c(3, 0);
    iss.read(a.data(), 3);
    assert(iss.gcount() == 3);
    is.read(b.data(), 2);
    assert(is.gcount() == 2);
    assert(iss.gcount() == 3);
    iss.read(c.data(), 3);
    assert(iss.gcount() == 3);
    assert("ABC" == a);
    assert("YZ" == b);
    assert("123" == c);
}