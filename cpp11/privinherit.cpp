// private inheritance gives derived access to base class implementation without exposing it outside

#include <iostream>

class Base {
public:
    void f1_pub() {}
protected:
    void f1_pro() {}
private:
    void f1_priv() {}
    void test() {
        f1_pub();
        f1_pro();
        f1_priv();
    }
};

class Derived1 : public Base {
public:
    void test() {
        f1_pub();
        f1_pro();      // derived class can access base protected
//        f1_priv();  // derived class cannot access base private
    }
};

class PrivateInherited : private Base {
public:
    void test() { // same as public inheritance
        f1_pub();
        f1_pro();
    }
};
class PrivateInheritedInherited : private PrivateInherited {
public:
    void test() {
//        f1_pub();  // not inherited - PrivateInherited::f1_pub() was private
//        f1_pro();
    }
};

int main() {
    Derived1 c1{};
    PrivateInherited c2{};

    c1.f1_pub();    // public inheritance leave public as public
//    c1.f1_pro();  // error

//    c2.f1_pub();  // error - private inheritance make this private
//    c2.f1_pro();  // error

}
