// see difference between atoi and stoi. Biggest difference is that latter raise exception when there is no leading num char.

#include <string>
#include <stdexcept>
#include <cassert>

using namespace std;
int main() {
    assert(stoi(" \t\n123") == 123); // leading space characters are ignored
    assert(stoi("023") != 023);
    assert(stoi("023") == 23);
    assert(stoi("+23") == 23);
    assert(stoi("-23") == -23);
    assert(stoi("023", nullptr, 0) == 023); // pass raddix=0 to automatically detect raddix
    assert(stoi("31x23") == 31); // use the leading numeric characters
    assert(stoi("31 23") == 31); // space characters in the middle ends the number
    {
        bool caught = false;
        try {
            stoi("a 23");
        } catch(std::invalid_argument& e) {
            caught = true;
        }
        assert(caught);
    }
    assert(stoi("123", nullptr, 4) == 27); // raddix=4
    assert(stoi("124", nullptr, 4) == 6); // raddix=4 -> "4" is invalid character
    assert(stoi("1z", nullptr, 36) == 36 + 35); // raddix=36

    // to_chars not supported yet
//    string buf(100, 0);
//    to_chars(buf.begin(), buf.end(), 36+35, 36);

    assert(atoi(" \t\n123") == 123);
    assert(atoi("023") == 23);
    assert(atoi("+23") == 23);
    assert(atoi("-23") == -23);
    assert(strtol("023", nullptr, 0) == 023);
    assert(atoi("31a23") == 31);
    assert(atoi("31 23") == 31);
    assert(atoi("a23") == 0); // conversion error returns 0

}

