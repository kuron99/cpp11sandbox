// gc functions are defined since C++11, but the implementation is empty

#include <memory>
int main() {
    int x;
    std::declare_reachable(&x);
}