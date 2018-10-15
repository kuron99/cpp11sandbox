#include <iostream>
#include <vector>
#include "watch.h"

using namespace std;

int main() {
    watch w1;
    vector<long long> v{};
    v.reserve
    try {
        for (int j=0 ; j < 100; j++) {
            w1.reset();
            for (size_t i = 0; i < 10000000; i++) {

            }
            cout << w1.stop()/1000 << "," << s.capacity() << endl;
        }
    } catch (std::bad_alloc& ) {
        cout << "std::bad_alloc exception caught" << endl;
    }
    cout << "finish" << endl;
}
