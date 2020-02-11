
#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

int main() {
    {
        // eof
        stringstream ss{};
        ss << "ABC";
        assert(ss.good());
        string s{};
        int a;
        ss >> s;
        assert(!ss.good());
        assert(!ss.fail());
        assert(ss.eof());
        assert(!ss.bad());
    }
    {
        // fail
        stringstream ss{};
        ss << "ABC";
        assert(ss.good());
        string s{};
        int a;
        char c;
        ss >> a;
        assert(!ss.good());
        assert(ss.fail());
        assert(!ss.eof());
        assert(!ss.bad());
        ss.clear();
        ss >> c;
        assert(ss.good());
        assert(!ss.fail());
        assert(!ss.eof());
        assert(!ss.bad());
    }
    {
        // bad
        istream is{nullptr};
        assert(!is.good());
        assert(is.fail());
        assert(!is.eof());
        assert(is.bad());
        is.clear();  // clear doesn't clear unrecoverable errors
        assert(!is.good());
        assert(is.fail());
        assert(!is.eof());
        assert(is.bad());
    }
    {
        // eof exception
        stringstream ss{};
        ss.exceptions(ios_base::eofbit);
        ss << "ABC";
        assert(ss.good());
        string s{};
        bool caught = false;
        try {
            ss >> s;
        } catch (std::ios_base::failure& e) {
            cout << e.what() << endl;
            caught = true;
        }
        assert(caught);
        assert(!ss.good());
        assert(!ss.fail());
        assert(ss.eof());
        assert(!ss.bad());
    }
}