// typedef/using respects public/protected/private specifier

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
};

int main() {
    C1::mytype1 a;
    C1::t1 aa;
//    C1::mytype2 b;
//    C1::t2 bb;
//    C1::mytype3 c;
//    C1::t3 cc;
}