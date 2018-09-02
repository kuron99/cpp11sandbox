// class size on LP64 environment - int : 32bit, long&pointers : 64bit, alignment : 32bit

#include <cassert>

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

int main() {
    static_assert(sizeof(char) == 1, "");
    static_assert(sizeof(int) == 4, "");
    static_assert(sizeof(long) == 8, "");
    static_assert(sizeof(long long) == 8, "");
    static_assert(sizeof(float) == 4, "");
    static_assert(sizeof(double) == 8, "");
    static_assert(sizeof(long double) == 16, "");

    static_assert(sizeof(C1) == 1, ""); // empty class should have size > 0
    static_assert(sizeof(WithInt) == 4, "");
    static_assert(sizeof(WithInt2) == 8, "");
    static_assert(sizeof(WithManyVars) == 64, ""); // LP64 alignment is 64bit
    static_assert(sizeof(WithManyVarsAligned) == 48, ""); // LP64 alignment is 64bit
    static_assert(sizeof(WithBitField1_31) == 4, ""); //
    static_assert(sizeof(WithBitField33_31) == 8, ""); //
    static_assert(sizeof(WithBitField1_63) == 8, ""); //
    static_assert(sizeof(WithBitField63_1) == 8, ""); //
    static_assert(sizeof(WithPointer) == 8, "");

}