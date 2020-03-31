// ostringstream&& can accept operations such as << but difficult to convert to string

#include <sstream>
#include <iostream>

std::string some() {
    return "ABC";
}

int main() {
    std::ostringstream ss;
//    std::cout << ((std::ostringstream {} << "ABC").str() ) << std::endl;  // << returns ostream, so str() cannot be called

    ss << some();
    std::cout << ss.str() << std::endl;
    std::cout << reinterpret_cast<void*>(ss.rdbuf()) << std::endl;
//    std::cout << ss.rdbuf() << std::endl; // not sure why, but this causes reset of cout << invisible
    std::cout << ss.rdbuf()->str() << std::endl;

//    std::cout << (std::ostringstream {} << some()).rdbuf()->str() << std::endl;  // rdbuf() returns string_streambuf, so str() cannot be called

}

