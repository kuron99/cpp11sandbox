#include <iostream>
#include <memory>
class C1 {
public:
    int f1() {
        return 1;
    }
private:
    int x;
};
// nullptr access doesn't always result in SEGV, simply undefined behavior
int main() {
    C1* c1 = nullptr;
    std::cout << c1->f1() << std::endl;
    return 0;
}