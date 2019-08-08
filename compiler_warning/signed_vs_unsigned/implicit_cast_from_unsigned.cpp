// how to enable warning on comparison between signed and unsigned?
// gcc: -Wall
// clang: -Wall -Wextra

#include <iostream>
#include <string>
#include <vector>

void do_something(int) {}

void fun (const std::vector<int> &vec) {
    for (int i = 0; i < vec.size() ; ++i) // comparison between signed/unsigned
        do_something(vec[i]);
}

int main()
{
    std::vector<int> foo;
    fun(foo);
}
