// std::thread calls std::terminate on destruction
#include <thread>

void f() {

}
int main() {
    std::thread th2{f};  // std::terminate called on destruction
}