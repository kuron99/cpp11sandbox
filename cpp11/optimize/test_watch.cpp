#include <iostream>
#include <vector>
#include "watch.h"

using namespace std;

int main() {
    watch w1;
    watch w2;
    vector<long long> v{};
    v.reserve(100000000);
    try {
        for (int j = 0; j < 100; j++) {
            w2.reset();
            const static long long len = 10000000;
            for (size_t i = 0; i < len; i++) {
                w1.reset();
                v.push_back(w1.stop());
            }

            const long long int dur = w2.stop();
            cout << "j" << j << "duration: " << dur << " per loop: " << (double) dur / len << "microsec." << endl;
        }
    } catch (std::bad_alloc&) {
        cout << "std::bad_alloc exception caught" << endl;
    }
}
