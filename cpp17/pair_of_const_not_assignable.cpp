// copy constructor of std::pair is implicitly deleted when one of the parameter is const
#include <tuple>

int main() {
    using const_pair = std::pair<const int, int>;
    const_pair p1{1,100};
    const_pair p2{2,200};

//    p2 = p1; // error

    using pair = std::pair<int, int>;
    pair p100{1,100};
    pair p200{2,200};

    p200 = p100;
}