

#include <stdio.h>
#include <assert.h>

float f1(float a) {
    return a * 2.0;
}

int main() {
    double d = f1(0.1f);
    float f = (float)d;
    assert(f == f1(0.1f));
}
