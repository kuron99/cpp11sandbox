// experiment with std::is_same<T, U>
// working fine to test types cv-quialified C1 ref or pointers

#include <iostream>

#include <boost/type_index.hpp>
class C1 {

};

int main() {
    C1 c1{};
    C1 &rc1 = c1;
    C1 *pc1 = &c1;
    C1 **ppc1 = &pc1;
    C1 *&rpc1 = pc1;
    C1 &&rrc1 = C1{};
//    C1&* prc1 = &rc1; // compiler error - C++ doesn't have "point to reference"
    static_assert(std::is_same<decltype(c1), C1>::value, "true");
    static_assert(std::is_same<decltype(rc1), C1 &>::value, "true");
    static_assert(std::is_same<decltype(pc1), C1 *>::value, "true");
    static_assert(std::is_same<decltype(ppc1), C1 **>::value, "true");
    static_assert(std::is_same<decltype(rpc1), C1 *&>::value, "true");
    static_assert(std::is_same<decltype(rrc1), C1 &&>::value, "true");

    const C1 cc1{};
    volatile C1 vc1{};
    const C1 &rcc1 = C1{};
    const C1 &&rrcc1 = C1{};
    static_assert(std::is_same<decltype(cc1), const C1>::value, "true");
    static_assert(std::is_same<decltype(vc1), volatile C1>::value, "true");
    static_assert(std::is_same<decltype(rcc1), const C1 &>::value, "true");
    static_assert(std::is_same<decltype(rrcc1), const C1 &&>::value, "true");

    int arr[10] = {100};
    static_assert(std::is_same<decltype(arr), int[10]>::value, "true");
    static_assert(!std::is_same<decltype(arr), int[]>::value, "true");
    static_assert(std::is_same<std::decay<decltype(arr)>::type, int*>::value, "true");

    // reference to array variable
    int (&refarr)[10] = arr;
    static_assert(std::is_same<decltype(refarr), int(&)[10]>::value, "true");
    static_assert(!std::is_same<decltype(refarr), int(&)[1]>::value, "true");
    static_assert(std::is_same<std::decay<decltype(refarr)>::type, int*>::value, "true");  // reference to array decays to pointer

    // pointer to array variable
    int (*ptrarr)[10] = &arr;
    static_assert(std::is_same<decltype(ptrarr), int(*)[10]>::value, "true");
    static_assert(!std::is_same<decltype(ptrarr), int(*)[1]>::value, "true");
    static_assert(std::is_same<std::decay<decltype(ptrarr)>::type, int(*)[10]>::value, "true");  // decay doesn't happen on pointer to array
}
