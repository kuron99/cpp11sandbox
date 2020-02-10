// input stream iterator read and copy to its own data area

#include <iostream>
#include <iterator>
#include <sstream>
#include <cassert>
using namespace std;

int main() {
    {
        stringstream ss{"1 2 3 4"};
        istream_iterator<int> in(ss); // 1 was read and copied
        assert(1 == *in++);
        assert(2 == *in++);
        assert(3 == *in++);
    }
    {
        stringstream ss{};
        ostream_iterator<int> in(ss, " ");
        in = 3;
        in = 2;
        in = 1;
        assert("3 2 1 " == ss.str());
    }
    {
        stringstream ss{};
        ostream_iterator<int> in(ss);
        in = 3;
        in = 2;
        in = 1;
        assert("321" == ss.str());
    }
}