#include <iostream>
#include "watch.h"

using namespace std;

int main() {
    watch w1;
    try {
        string s("");
        for (int j=0 ; j < 100; j++) {
            w1.reset();
            for (size_t i = 0; i < 10000000; i++) {
                s += "a";
            }
            cout << w1.stop()/1000 << "," << s.capacity() << endl;
        }
    } catch (std::bad_alloc& ) {
        cout << "std::bad_alloc exception caught" << endl;
    }
    cout << "finish" << endl;
}
