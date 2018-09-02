// experiment with std::is_* functions

#include <functional>
class C2 {};
class C1 : C2 {};

enum E1 {

};
enum class EC1 {

};

struct S1 {};

union U1 {};

class C11 {
    int x_;
    double y_;
};
class C10 {
protected:
    int x_;
    double y_;
    int z_;
    C11 c_;
};

class C12 {
public:
    int x_;
    int &xx_;
private:
    int z_;
};

class C13 {
    int x_ = 100;
};

class ExplicitlyConvertibleToInt {
public:
    explicit operator int() {
        return 1;
    }
};
class ImplicitlyConvertibleToInt {
public:
    operator int() {
        return 1;
    }
};

class ExplicitlyConvertibleFromInt {
public:
    explicit ExplicitlyConvertibleFromInt(int x) {}
};
class ImplicitlyConvertibleFromInt {
public:
    ImplicitlyConvertibleFromInt(int x) {}
};

int (*fp1)(int x);
int func1(int x) { return x+1; }

class Empty {};
class EmptyInheried : Empty {};
class EmptyInheriedConstructor : Empty {
    EmptyInheriedConstructor() {};
};

int main() {
    C1 c1{};
    C1& rc1 = c1;
    C1&& rrc1 = C1{};
    static_assert(!std::is_reference<decltype(c1)>::value, "true");
    static_assert(!std::is_rvalue_reference<decltype(c1)>::value, "true");
    static_assert(!std::is_lvalue_reference<decltype(c1)>::value, "true");
    static_assert(std::is_reference<decltype(rc1)>::value, "true");
    static_assert(std::is_lvalue_reference<decltype(rc1)>::value, "true");
    static_assert(!std::is_rvalue_reference<decltype(rc1)>::value, "true");

    using RC1 = C1&;
    static_assert(std::is_reference<RC1>::value, "true");
    static_assert(!std::is_rvalue_reference<RC1>::value, "true");
    static_assert(std::is_lvalue_reference<RC1>::value, "true");

    static_assert(!std::is_base_of<C1, C2>::value, "true");
    static_assert(std::is_base_of<C2, C1>::value, "true");
    static_assert(std::is_base_of<C1, C1>::value, "true");
    static_assert(std::is_base_of<C2, C2>::value, "true");
    static_assert(!std::is_base_of<int, double>::value, "true");

    static_assert(std::is_pod<S1>::value, "true");
    static_assert(std::is_pod<C10>::value, "true");

    // public&private fields make C12 non standard layout
    static_assert(!std::is_pod<C12>::value, "true");
    static_assert(!std::is_standard_layout<C12>::value, "true");
    static_assert(std::is_trivial<C12>::value, "true");

    // default initialize = 100 causes C13 non-trivial
    static_assert(!std::is_pod<C13>::value, "true");
    static_assert(std::is_standard_layout<C13>::value, "true");
    static_assert(!std::is_trivial<C13>::value, "true");

    static_assert(std::is_enum<E1>::value, "true");
    static_assert(std::is_enum<EC1>::value, "true"); // enum class is enum type
    static_assert(!std::is_enum<C1>::value, "true");

    static_assert(std::is_void<void>::value, "true");
    static_assert(!std::is_void<void*>::value, "true");

    static_assert(std::is_pointer<void*>::value, "true");
    static_assert(std::is_pointer<void**>::value, "true");
    static_assert(std::is_pointer<void***>::value, "true");
    static_assert(!std::is_pointer<int*&>::value, "true");
    static_assert(!std::is_pointer<int**&>::value, "true");

    static_assert(!std::is_class<int>::value, "true");
    static_assert(!std::is_class<E1>::value, "true");  // enum is not class
    static_assert(!std::is_class<EC1>::value, "true"); // enum class is not either
    static_assert(std::is_class<S1>::value, "true");
    static_assert(!std::is_class<U1>::value, "true");  // union is not either

    static_assert(!std::is_empty<E1>::value, "true");  // enum is not class, so is not empty
    static_assert(!std::is_empty<EC1>::value, "true"); // enum class is not either
    static_assert(std::is_empty<S1>::value, "true");
    static_assert(std::is_empty<Empty>::value, "true");
    static_assert(std::is_empty<EmptyInheried>::value, "true");
    static_assert(std::is_empty<EmptyInheriedConstructor>::value, "true");

    static_assert(std::is_object<U1>::value, "true");
    static_assert(std::is_object<int>::value, "true");
    static_assert(!std::is_object<int&>::value, "true"); // reference is not object type
    static_assert(!std::is_object<void>::value, "true"); // void is not object type
    static_assert(std::is_object<void*>::value, "true"); // void pointer is object type
    static_assert(std::is_object<decltype(fp1)>::value, "true"); // function pointer is object type
    static_assert(!std::is_object<decltype(*fp1)>::value, "true"); // function is not object
    static_assert(!std::is_object<decltype(func1)>::value, "true"); // function is not object

    static_assert(std::is_function<decltype(func1)>::value, "true");

    std::function<int(int)> func_object = func1;
    std::function<int(void)> lambda_object = [] { return 1; };
    static_assert(!std::is_function<std::function<int(int)>>::value, "true"); // std::function is not function at all
    static_assert(std::is_class<std::function<int(int)>>::value, "true");
    static_assert(std::is_object<std::function<int(int)>>::value, "true");
    static_assert(!std::is_function<std::function<int(int)>>::value, "true");
    static_assert(!std::is_function<decltype(func_object)>::value, "true");
    static_assert(std::is_class<decltype(func_object)>::value, "true");
    static_assert(!std::is_function<decltype(lambda_object)>::value, "true");
    static_assert(std::is_class<decltype(lambda_object)>::value, "true");

    static_assert(std::is_function<int(int)>::value, "true"); // this is the type for function
    static_assert(std::is_function<void()>::value, "true");
    static_assert(std::is_function<void()&&>::value, "true");
    static_assert(std::is_function<C1&&(const C1&) const &>::value, "true");

    typedef int (*Func10)(int); // pointer type for function
    static_assert(std::is_pointer<Func10>::value, "true");
    static_assert(!std::is_function<Func10>::value, "true"); // function pointer is not a function
    static_assert(std::is_same<Func10, decltype(fp1)>::value, "true");

    static_assert(std::is_fundamental<int>::value, "true");
    static_assert(std::is_fundamental<std::nullptr_t>::value, "true");
    static_assert(std::is_fundamental<void>::value, "true");
    static_assert(!std::is_fundamental<void*>::value, "true");
    static_assert(!std::is_fundamental<int*>::value, "true");
    static_assert(!std::is_fundamental<int&>::value, "true");
    static_assert(!std::is_fundamental<C1>::value, "true");

    class Signed {
    public:
        bool operator <(const Signed& rhs) {
            return true;
        }
    };

    static_assert(std::is_signed<int>::value, "true");
    static_assert(!std::is_signed<bool>::value, "true");
    static_assert(!std::is_signed<unsigned int>::value, "true");
    static_assert(std::is_signed<double>::value, "true");
    static_assert(std::is_signed<double>::value, "true");
    static_assert(std::is_signed<int_least8_t>::value, "true");
    static_assert(!std::is_signed<uint64_t >::value, "true");
    static_assert(!std::is_signed<Signed>::value, "true");

    static_assert(std::is_convertible<int, double>::value, "true");
    static_assert(std::is_convertible<double, int>::value, "true");
    static_assert(!std::is_convertible<C1, int>::value, "true");
    static_assert(!std::is_convertible<ExplicitlyConvertibleToInt, int>::value, "true");
    static_assert(!std::is_convertible<int , ExplicitlyConvertibleFromInt>::value, "true");
    static_assert(std::is_convertible<ImplicitlyConvertibleToInt, int>::value, "true");
    static_assert(std::is_convertible<int , ImplicitlyConvertibleFromInt>::value, "true");
}
