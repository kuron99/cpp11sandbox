// template template parameter allows passing only the std::vector part of std::vector<std::string> used by C2
// Don't forget vector has allocator argument.
// Class template is a map from type(s) to a type.
// Template template parameters are also maps from type(s) to a type.
// C2 (class template with template template parameters) is a map whose argument is a map.

#include <vector>
#include <list>
#include <iostream>

template <template <typename, typename> class C1>
class C2 {
    using data_type = C1<std::string, std::allocator<std::string>>;
    data_type data_{};
public:
    C2(data_type data) : data_(std::move(data)) {}
    void print_all() {
        for(auto& e : data_) {
            std::cout << e << std::endl;
        }
    }
};

int main() {
    std::vector<std::string> strings_vector{"AAA", "BBB"};
    C2<std::vector> c2vector{std::move(strings_vector)};
    c2vector.print_all();

    std::list<std::string> strings_list{"AAA", "BBB"};
    C2<std::list> c2list{std::move(strings_list)};
    c2list.print_all();
}
