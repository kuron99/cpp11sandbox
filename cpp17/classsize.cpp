// class size on LP64 environment - int : 32bit, long&pointers : 64bit, alignment : 32bit

#include <cassert>
#include <utility>
#include "boost/multiprecision/cpp_int.hpp"

class C1 {
};

class WithInt {
    int x_;
};
class WithInt2 {
    int x_;
    int y_;
};
class WithManyVars {
    char c_;
    long double ld_;
    double d_;
    int x_;
    double e_;
    float f_;
};
class WithManyVarsAligned {
    char c_;
    int x_;
    float f_;
    double d_;
    double e_;
    long double ld_;
};
class WithBitField1_31 {
    int x_:1;
    int y_:31;
};
class WithBitField1_63 {
    long x_:1;
    long y_:63;
};
class WithBitField63_1 {
    long x_:63;
    long y_:1;
};
class WithBitField33_31 {
    long x_:33;
    long y_:31;
};
class WithPointer {
    C1* ptr_;
};
class WithReference {
public:
    explicit WithReference(C1& x) : ref_(x) {}
    C1& ref_;
};
class WithRvalueReference {
public:
    explicit WithRvalueReference(C1&& x) : ref_(std::move(x)) {}
    C1&& ref_;
};
class LongAndInt {
    long x_;
    int y_;
};
class IntAndLong {
    int x_;
    long y_;
};

struct S1 {
    short s;
    char c[3];
};

struct S2 {
    char c[10];
    char c2;
};

struct S3 {
    double d;
    long long ll;
    char c;
};

union U {
    char str[17];
    double[2];
};

int main() {
    static_assert(sizeof(char) == 1);
    static_assert(sizeof(int) == 4);
    static_assert(sizeof(long) == 8);
    static_assert(sizeof(long long) == 8);
    static_assert(sizeof(float) == 4);
    static_assert(sizeof(double) == 8);
    static_assert(sizeof(long double) == 16);
    static_assert(sizeof(boost::multiprecision::int128_t) == 16 + 16);
    static_assert(sizeof(boost::multiprecision::int256_t) == 32 + 16);
    static_assert(sizeof(boost::multiprecision::int512_t) == 64 + 16);
    static_assert(sizeof(boost::multiprecision::int1024_t) == 128 + 16);

    static_assert(sizeof(C1) == 1); // empty class should have size > 0
    static_assert(sizeof(WithInt) == 4);
    static_assert(sizeof(WithInt2) == 8);
    static_assert(sizeof(WithManyVars) == 64); // LP64 alignment is 64bit
    static_assert(sizeof(WithManyVarsAligned) == 48); // LP64 alignment is 64bit
    static_assert(sizeof(WithBitField1_31) == 4); //
    static_assert(sizeof(WithBitField33_31) == 8); //
    static_assert(sizeof(WithBitField1_63) == 8); //
    static_assert(sizeof(WithBitField63_1) == 8); //
    static_assert(sizeof(WithPointer) == 8);
    static_assert(sizeof(WithReference) == 8);
    static_assert(sizeof(WithRvalueReference) == 8);
    static_assert(sizeof(LongAndInt) == 16);
    static_assert(sizeof(IntAndLong) == 16);
    C1 c1{};
    WithReference wr{c1};
    static_assert(sizeof(wr.ref_) == 1); // this is the size of C1, not reference
    WithRvalueReference wrr{C1{}};
    static_assert(sizeof(wrr.ref_) == 1); // this is the size of C1, not reference

    static_assert(sizeof(S1) == 6);
    static_assert(alignof(S1) == 2);
    static_assert(sizeof(S2) == 11);
    static_assert(alignof(S2) == 1);
    static_assert(sizeof(S3) == 24);
    static_assert(alignof(S3) == 8);
    static_assert(sizeof(U) == 17);
    static_assert(alignof(S3) == 8);
}