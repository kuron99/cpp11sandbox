// ostringstream can share buffer with ostream
// Don't forget to specify ios_base::ate to avoid unexpected(unspecified) buffer

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
        ss << endl;
        ss << 1;
        ss << endl;
        ss << 2.0;
        ss << endl;
        string s{};
        int a = 0;
        double d = 0;
        ss >> s;
        ss >> a;
        ss >> d;
        assert(s == "ABC");
        assert(a == 1);
        assert(d == 2.0);
    }
    {
        ss << "ABC";
        int a = 0;
        assert(!ss.fail());
        ss >> a;
        assert(ss.fail());
        assert(a == 0);
        string s{};
        ss >> s;
        assert(ss.fail());
        assert(s.empty());
    }
}