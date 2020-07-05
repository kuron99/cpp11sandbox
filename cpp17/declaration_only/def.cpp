// simply missing definition is not an error

#include "dec.h"
#include <iostream>

int main() {
    std::cout << "main" ;

    C c;
    std::cout << c.x() ;
}



