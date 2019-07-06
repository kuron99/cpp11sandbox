// gcc seems lenient for the template template parameter
// std::vector has 2 parameters, but specifying only one allowed by gcc, not by clang

#include <vector>
#include <cassert>

template <template<class> class Vector>
class C1 {
public:
    Vector<int> values;
};

int main() {
    C1<std::vector> c1{};

    c1.values.emplace_back(3);

    assert(c1.values[0] == 3);

    return 0;
}
