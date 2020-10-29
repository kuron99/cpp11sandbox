#include <iostream>
#include <sstream>

int main() {
    std::stringstream ss;
    ss.exceptions(std::ios::badbit | std::ios::eofbit | std::ios::failbit);
    for(int i=0; i < 30000; ++i) {
        ss << "xxxxxxxxxxaaaaaaaaaaaaaaaaaaaaaaa" << i;
        if (i % 100 == 0) {
            std::cout << i << std::endl;
        }
    }
    std::cout << ss.str() << std::endl;
}
