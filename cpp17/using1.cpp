// typedef/using respects public/protected/private specifier
// though function using private type can be accessed from client

#include <cassert>

class C1 {
public:
    using mytype1 = int;
    typedef int t1;
protected:
    using mytype2 = int;
    typedef int t2;
private:
    using mytype3 = int;
    typedef int t3;
public:
    void set_mytype3(mytype3 x) {
        x_ = x;
    }
    mytype3 get_mytype3() {
        return x_;
    }
private:
    mytype3 x_{};
};

int main() {
    C1::mytype1 a;
    C1::t1 aa;

//    C1::mytype2 b;
//    C1::t2 bb;
//    C1::mytype3 c;
//    C1::t3 cc;

    C1 c{};
    c.set_mytype3(100); // client doesn't know mytype3 is int, but calling is ok
    assert(100 == c.get_mytype3());
}