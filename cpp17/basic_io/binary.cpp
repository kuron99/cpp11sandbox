// ostringstream can share buffer with ostream
// Don't forget to specify ios_base::ate to avoid unexpected(unspecified) buffer

#include <iostream>
#include <sstream>
#include <cstring>
#include <cassert>

using namespace std;
using namespace std::string_literals;

int main() {
    stringstream ss{ios_base::in|ios_base::out|ios_base::binary};
    {
        ss << "ABC";
        ss << 1;
        ss << 2.0;
        cout << ss.str();
    }
}