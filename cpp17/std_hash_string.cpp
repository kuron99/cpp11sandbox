// std::hash to std::string uses murmur3, so the value is not trivial

#include <string>
#include <iostream>

int main() {

    std::cout << std::hash<std::string>()("a") << std::endl;
    std::cout << std::hash<std::string>()("b") << std::endl;
    std::cout << std::hash<std::string>()("c") << std::endl;
    std::cout << std::hash<std::string>()("d") << std::endl;

    std::cout << std::hash<std::string>()("aa") << std::endl;

}