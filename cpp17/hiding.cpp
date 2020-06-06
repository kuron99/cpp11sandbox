// mysterious message "changes meaning" with name hiding

#include <cassert>

class func {
public:
    int operator()() {
        return -1;
    }

};

class C1 {
public:
    using func_type = func;  // this line triggers "changes meaning of xxx from yyy" error message

    int func() {
        return f1();
    }
private:
    class func f1{};
};

int main() {
    C1 c1;
    assert(-1 == c1.func());
}