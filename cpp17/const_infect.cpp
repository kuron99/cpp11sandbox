// if container is const, [] will return the const& to the element

#include <iostream>
#include <vector>
#include <boost/type_index.hpp>

int main() {
    std::vector<char*> constants{};
    std::string str("ABC");
    char* a = str.data();
    constants.emplace_back(a);
    std::cout << boost::typeindex::type_id_with_cvr<decltype(constants[0])>() << std::endl; // shows "char*&"

    auto const& const_constants = constants;
    std::cout << boost::typeindex::type_id_with_cvr<decltype(const_constants[0])>() << std::endl; // shows "char* const&"

    // the returned reference is const, but it's type is still char*, so it can be changed:
    auto* b = const_constants[0];
    b[0] = 'X';
    std::cout << b << std::endl;
}