// friend function defined in the class - usable to mixin related non-member function
// - they are actually not the member function
// - friend defined in a class requires args. dependent lookup, so it can avoid function call with non-related classes
// - the example use CRTP

#include <iostream>

template <typename T>
class FriendBase {
public:
    friend inline void f1_pub_f(T&) {}
protected:
    friend inline void f1_pro_f(T&) {}
private:
    friend inline void f1_priv_f(T&) {}
    void test() {
        // need arg. dependent lookup, otherwise f1_pub_f are not visible even inside from here
        FriendBase fb;
        f1_pub_f(fb);  // fried functions are actually not in this class
        f1_pro_f(fb);
        f1_priv_f(fb);
    }
};

class PrivateInheritedFriend : private FriendBase<PrivateInheritedFriend> {
    void test() {
        f1_pub_f(*this);
        f1_pro_f(*this);
        f1_priv_f(*this);
    }
};

int main() {
    PrivateInheritedFriend pf;
    f1_pub_f(pf);
    f1_pro_f(pf);
    f1_priv_f(pf);
}
