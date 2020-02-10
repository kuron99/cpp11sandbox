// ostringstream can share buffer with ostream
// Don't forget to specify ios_base::ate to avoid unexpected(unspecified) buffer

#include <iostream>
#include <sstream>
#include <cstring>
#include <cassert>

using namespace std;
using namespace std::string_literals;

int main() {
    stringstream ss_no_option{"000"s, ios_base::ate}; // without in or out, the behavior seems unexpected
    {
        assert(ss_no_option);
        ss_no_option << "ABC";
        string s{ss_no_option.str()};
//        assert("000" == ss_no_option.str()); // result differs between LLVM-libc++ vs gcc-libstdc++
    }

    stringstream ss{"000"s, ios_base::out|ios_base::ate};
    {
        assert(ss);
        ostream os{ss.rdbuf()};
        ss << "ABC";
        os << "XYZ";
        assert("000ABCXYZ" == ss.str());
    }
    istringstream iss_out_option{"000"s, ios_base::out|ios_base::ate}; // with out option for input stream simply ignored
    {
        assert(iss_out_option);
        string s{};
        iss_out_option >> s;
        assert(iss_out_option);
        assert("000" == s);
        assert(iss_out_option.eofbit);
    }
    ostringstream oss_in_option{"000"s, ios_base::in|ios_base::ate}; // with in option for output stream simply ignored
    {
        assert(oss_in_option);
        oss_in_option << "ABC";
        assert(oss_in_option);
        assert("000ABC" == oss_in_option.str());
    }
}