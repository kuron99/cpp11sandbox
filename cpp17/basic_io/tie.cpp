// tie is to call flush() on tied output stream synchronously on IO to *this
// it doesn't affect content of each stream

#include <iostream>
#include <sstream>
#include <cstring>
#include <cassert>

using namespace std;
using namespace std::string_literals;

int main() {
    stringstream ss{};
    {
        ss << "ABC";
        assert(ss.tie() == nullptr);
        stringstream ss2{"XYZ"};
        ss.tie(&ss2);
        assert(ss.tie() == &ss2);
        assert(ss.str() == "ABC");
        assert(ss2.str() == "XYZ");
        ss << "000";
        assert(ss.str() == "ABC000");
        assert(ss2.str() == "XYZ");
    }
}