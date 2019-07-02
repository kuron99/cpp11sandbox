// variable template doesn't need to have same type as the primary

#include <iostream>
#include <cassert>

template<int x>
char y = 0x48;

template<>
double y<42> = 2.5;

char c {y<17>};

double d {y<42>};

int main() {
    assert(0x48 == y<60>);
    assert(2.5 == y<42>);
}