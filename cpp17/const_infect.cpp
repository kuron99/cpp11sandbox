// if container is const, [] will return the const& to the element

#include <iostream>
#include <vector>
#include <boost/type_index.hpp>

int main() {
    std::vector<char*> constants{};
    char* a = "ABC";
    constants.emplace_back(a);
    std::cout << boost::typeindex::type_id_with_cvr<decltype(constants[0])>() << std::endl; // shows "char*&"

    auto const& const_constants = constants;
    std::cout << boost::typeindex::type_id_with_cvr<decltype(const_constants[0])>() << std::endl; // shows "char* const&"
}