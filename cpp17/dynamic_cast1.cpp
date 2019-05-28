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
class D : public C { public: virtual ~D() {};std::int64_t x_{}; };
class E : public C { public: virtual ~E() {};std::int64_t x_{}; };
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
    {
        auto d = static_cast<D*>(&f);
        auto e = dynamic_cast<E*>(d);
        assert(e != nullptr);
//    auto c = static_cast<C*>(&f); // F cannot be cast to C, that is ambiguous
//        auto d2 = static_cast<D*>(e); // cross cast not allowed by static_cast
        e->x_ = 100;
        auto d2 = static_cast<D*>(static_cast<A*>(e)); // no compile error, but this is ill-formed
        assert(d2 != nullptr);
        assert(d2->x_ == 100);

        auto c1 = static_cast<C*>(static_cast<E*>(&f)); // castable to C through non-ambiguous class
        auto c2 = static_cast<C*>(static_cast<D*>(&f));
        assert(reinterpret_cast<void*>(c1) != reinterpret_cast<void*>(c2));
        auto f1 = dynamic_cast<F*>(c1);
        auto f2 = dynamic_cast<F*>(c2);
        assert(f1 == f2);
        auto a1 = dynamic_cast<A*>(c1);
        auto a2 = dynamic_cast<A*>(c2);
        assert(a1 != a2);
        auto v1 = dynamic_cast<V*>(c1);
        auto v2 = dynamic_cast<V*>(c2);
        assert(v1 == v2);
    }

    E e{};
    {
        auto c = static_cast<C*>(&e);
        assert(nullptr != c);
        auto d = dynamic_cast<D*>(c);
        assert(nullptr == d);
    }

}
