#include <bitset>
#include <cassert>
using namespace std;

int main() {
    static_assert(alignof(bitset<1>) == 8);

    static_assert(sizeof(bitset<0>) == 1);
    static_assert(sizeof(bitset<1>) == 8);
    static_assert(sizeof(bitset<8>) == 8);
    static_assert(sizeof(bitset<64>) == 8);
    static_assert(sizeof(bitset<65>) == 16);
    static_assert(sizeof(bitset<128>) == 16);
    static_assert(sizeof(bitset<1024>) == 8*16);

    bitset<10> bs10{UINT64_MAX};
    assert(bs10.count() == 10);
    bitset<64> bs64{UINT64_MAX};
    assert(bs64.count() == 64);
    bitset<64> bs_1{static_cast<unsigned long long>(-1)};
    assert(bs_1.count() == 64);

    bs_1 <<= 1;
    bs_1 >>= 1;
    bs_1 >>= 1;

    assert(bs_1.count() == 62);

    bitset<64> bs1{1};
    assert(bs1.count() == 1);
    assert(bs1[0] == true);
    assert(bs1[1] == false);
    assert(bs1.test(0));
    assert(! bs1.test(1));

    static_assert(sizeof(unsigned long long) == 8);
    static_assert(sizeof(unsigned long) == 8);
    assert(bs1.to_string() == "0000000000000000000000000000000000000000000000000000000000000001");
    assert(bs1.to_ulong() == 1);
    assert(bs1.to_ullong() == 1);
    bitset<65> bs65{};
    bs65.set(64);
    assert(bs65.to_string() =="10000000000000000000000000000000000000000000000000000000000000000");
//    assert(bs65.to_ulong() == 0); // std::overflow_error
//    assert(bs65.to_ullong() == 0); // std::overflow_error
}