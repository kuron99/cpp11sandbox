// learn rules for dynamic_cast
// dynamic_cast involves 3 types, src, target, and runtime type

// src must be virtual, otherwise compile error
// target can be void*, which simply cast src ptr to most derived class and then to void*
// if parent is ambiguous, dynamic_rule

#include <cassert>
#include <iostream>

class A { public: virtual ~A() {};};
class V { public: virtual ~V() {}; std::int64_t z_{};};
class C : public A, public virtual V { public: virtual ~C() {};std::int64_t x_{}; };
class E : public C { public: virtual ~E() {};std::int64_t x_{}; };
class D : public C { public: virtual ~D() {};std::int64_t x_{}; };
class F : public D, public E { public: virtual ~F() {};std::int64_t x_{}; };

static_assert(sizeof(A) == 8);  // pointer to vtable
static_assert(sizeof(V) == 16); // pointer to vtable + int64
static_assert(sizeof(C) == 32); // pointer to vtable of A, and of V + int64(part of V) and int64
static_assert(sizeof(E) == 40); // C + int64
static_assert(sizeof(D) == 40); // C + int64
static_assert(sizeof(F) == 72); // pointer to vtable A, V and int64, int64, int64, int64

int main() {
    A a{};
    assert(nullptr == dynamic_cast<C*>(&a));
    void* a_ptr = dynamic_cast<void*>(&a);
    std::size_t a_ptr_int = reinterpret_cast<long>(a_ptr);
    assert(a_ptr == (void*)&a);
    assert(nullptr != dynamic_cast<void*>(&a));
    F f{};
    assert(nullptr != dynamic_cast<C*>(static_cast<D*>(&f)));
}
