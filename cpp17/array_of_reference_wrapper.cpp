#include <array>
#include <functional>
#include <cassert>
using namespace std;

class C1 {
public:
    C1(int x) : x_(x) {}
    int x_{1};
};

template<typename T, typename Array, size_t ... I>
auto reference_array(Array & arr, std::index_sequence<I...>) {
    return std::array<std::reference_wrapper<T>, sizeof ...(I)> { std::ref(arr[I]) ... };
}

template<typename T, size_t dim, typename Array>
auto reference_array(Array & arr) {
    return reference_array<T>(arr, std::make_index_sequence<dim>{});
}

int main() {
    std::array<int, 3> arr = { 1, 2, 3};
    std::array<std::reference_wrapper<int>, 3> arr2 = { ref(arr[0]), ref(arr[1]), ref(arr[2])};
    assert(arr2[2] == 3);

    auto a = reference_array<int, 3>(arr);
    assert(a[2] == 3);
    assert(a[1] == 2);
    assert(a[0] == 1);

    std::array<C1, 2> c1arr = { C1(2), C1(3)};
    auto c1arr_ref = reference_array<C1,2>(c1arr);
    C1 & cc = c1arr_ref[1];
    assert(cc.x_ == 3);
    cc.x_ = 1;
}
