// string capacity is 15 by default
// resize() changes the string length by truncation
// null terminator can be a part of the std::string

#include <string>
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;
int main() {
    string str;
    cout << "capacity:" << str.capacity() << endl;
    str.reserve(100);
    cout << "capacity:" << str.capacity() << endl;
    str.resize(9);
    memcpy(str.data(), "ABC", 3);
    str.resize(2);
    cout << "str.length:" << str.size() << endl;
    cout << "str:" << str << endl;

    str = "ABC";
    str.append(std::string(1, '\0'));
    assert(4 == str.size());
    str.append(std::string(1, 'A'));
    assert(5 == str.size());
}
