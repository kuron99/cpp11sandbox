
#include <string>
#include <iostream>
#include <cstring>

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
}
