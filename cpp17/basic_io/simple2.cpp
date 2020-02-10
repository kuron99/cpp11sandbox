// istringstream can be moved, the result is not ensured as empty

#include <iostream>
#include <sstream>
#include <cstring>
#include <cassert>

using namespace std;
using namespace std::string_literals;

int main() {
    istringstream iss{"ABC"s};
    istringstream iss2{move(iss)};
    string s{3, 0};
    iss.read(s.data(), s.size());
    assert(iss.gcount() == 0);
    assert(s == "\0\0\0");
}