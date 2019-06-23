// playing with meta function - that returns type(s) receiving type(s)

#include <type_traits>
// input is int
// pre-C++14 way
template <int N>
struct is_even {
    static const bool value;
};

template <int N>
const bool is_even<N>::value = N % 2 == 0;

// C++14 or later
template <int N>
constexpr bool is_even_v = N % 2 == 0;

// input is type pre-C++11
template <typename T>
struct add_pointer {
    typedef T* type;
};

template <typename T>
struct add_pointer2 {
    using type = T*;
};

template <typename T>
using add_pointer_cpp11_t = T*;

int main() {
    static_assert(is_even<2>::value);
    static_assert(!is_even<3>::value);

    static_assert(is_even_v<2>);
    static_assert(!is_even_v<3>);

    static_assert(std::is_same_v<add_pointer<int>::type, int*>);
    static_assert(std::is_same_v<add_pointer2<int>::type, int*>);
    static_assert(std::is_same_v<add_pointer_cpp11_t<int>, int*>);
}


