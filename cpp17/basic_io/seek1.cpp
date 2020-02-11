// seekp/seekg moves cursor for output and input separately

// tellp/tellg actually seek without moving cursor, so it clears or sets fail/eof state bits

#include <sstream>
#include <iostream>
#include <cassert>
using namespace std;

int main() {
    stringstream ss{};
    ss << "ABC";
    assert(ss.tellp() == 3);
    assert(ss.tellg() == 0);
    char a{};
    ss >> a;
    assert(a == 'A');
    assert(ss.tellp() == 3);
    assert(ss.tellg() == 1);

    ss.seekg(0);
    assert(ss.tellg() == 0);
    ss >> a;
    assert(a == 'A');
    assert(ss.tellg() == 1);
    ss.seekg(2);
    ss >> a;
    assert(a == 'C');
    assert(ss.tellg() == 3);

    ss.seekg(1);
    ss.seekp(0);
    ss << "DE";
    assert(ss.tellp() == 2);
    assert(ss.tellg() == 1);
    ss >> a;
    assert(a == 'E');
    ss >> a;
    assert(a == 'C');

    // seek simply clears eof state
    ss.seekg(4);
    assert(ss.fail());
    assert(!ss.eof());
    ss.clear();
    ss.seekg(3);
    assert(!ss.eof());
    assert(!ss.fail());
    ss.seekg(2);
    assert(!ss.eof());

    ss.str("");
    ss.clear();
    ss << "ABC";
    assert(ss.tellp() == 3);
    string s{};
    ss >> s;
    assert(s == "ABC");
    assert(ss.eof());
    assert(!ss.fail());
    assert(ss.rdbuf()->in_avail() == 0);
//    ss.clear();
    assert(!ss.fail());
    assert(ss.tellg() == 3); // causing ss fail
    assert(ss.fail());
    assert(ss.eof());

    ss.clear();
    ss.seekg(0);
    ss.seekg(-1, ios_base::end);
    assert(!ss.fail());
    assert(!ss.eof());
//    cout << ss.tellg() << endl;
    assert(ss.tellg() == 2);

    {
        stringstream ss{};
        ss << "ABC";
        ss.clear();
        ss.seekg(0);
        ss.seekg(0, ios_base::end);
        assert(!ss.fail());
        assert(!ss.eof());
        assert(ss.tellg() == 3);
    }
    {
        stringstream ss{};
        ss << "ABC";
        ss.clear();
        ss.seekg(0);
        ss.seekg(0, ios_base::cur);
        ss.seekg(4);
        assert(ss.tellg() == -1);
        assert(ss.fail());
        assert(!ss.eof());
        assert(ss.rdbuf()->in_avail() == 3);
    }
}