// Experiment passing reference to a class, which holds them to update values later
// Reference can be passed to other classes when they are initialized.
#include <iostream>

class C1 {
public:
    C1(int & a, double & b) : a_(a), b_(b) {}
    C1& a(int a) {
       a_ = a;
       return *this;
    }
    C1& b(double b) {
        b_ = b;
        return *this;
    }
private:
   int & a_;
   double & b_;
};

int main() {
    int x = 100;
    double y = 200.0;
    std::cout << "x = " << x << " y = " << y << std::endl;
    C1(x, y).a(1).b(2.0);
    std::cout << "x = " << x << " y = " << y << std::endl;
}