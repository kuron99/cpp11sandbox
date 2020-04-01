// receiving temp. obj with string_view

#include <cassert>
#include <string_view>
#include <string>

using namespace std::string_literals;

int f(std::string_view sv) {
    return sv.size();
}

std::string some() {
    return "ABC"s;
}

int main() {
    assert(3 == f(std::string("ABC")));
    assert(3 == f(some()));
}