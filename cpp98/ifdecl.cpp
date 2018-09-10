// not widely used, but you can declare a single variable within if/while condition
#include <iostream>
#include <cassert>

int main() {
    int x = 1;
    if (int y = x + 1) {
        std::cout << "y =" << y << std::endl;
        assert(y == 2);
    }
    int times = 0;
    int count = 10;
    while (int z = count) {
        std::cout << "z = " << z << " count = " << count << std::endl;
        count--;
        times++;
    }
    assert(times == 10);
}
