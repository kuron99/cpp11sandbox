#include <iostream>

using namespace std;

#define IIF(elem,cond) elem ## _ ## cond

#define CONSTRUCTOR_0(n)
#define CONSTRUCTOR_1(n) explicit n (int x) : x_(x) {}
#define DESTRUCTOR_0(n)
#define DESTRUCTOR_1(n) ~ n () {}
#define DEF_CONSTRUCTOR_0(n)
#define DEF_CONSTRUCTOR_1(n) n () : x_(-1) {}
#define COPY_CONSTRUCTOR_0(n)
#define COPY_CONSTRUCTOR_1(n) n (const n &c1) : x_(c1.x_) {}
#define COPY_ASSIGN_0(n)
#define COPY_ASSIGN_1(n) n &operator=(const n &) { return *this;}
#define MOVE_CONSTRUCTOR_0(n)
#define MOVE_CONSTRUCTOR_1(n) n ( n &&c1) : x_(c1.x_) { }
#define MOVE_ASSIGN_0(n)
#define MOVE_ASSIGN_1(n) n &operator=( n &&) { return *this; }

#define CLASS_DEF(name,has_constructor,has_destructor,default_constructible,copy_constructible,copy_assignable,move_constructible,move_assignable) \
class name { \
public: \
IIF(CONSTRUCTOR,has_constructor)(name) \
IIF(DESTRUCTOR,has_destructor)(name) \
IIF(DEF_CONSTRUCTOR,default_constructible)(name) \
IIF(COPY_CONSTRUCTOR,copy_constructible)(name) \
IIF(COPY_ASSIGN,copy_assignable)(name) \
IIF(MOVE_CONSTRUCTOR,move_constructible)(name) \
IIF(MOVE_ASSIGN,move_assignable)(name) \
int x() { return x_; } \
private: int x_; };

CLASS_DEF(C1,0,0,0,0,0,0,0)
CLASS_DEF(C2,1,0,0,0,0,0,0)
CLASS_DEF(C3,0,1,0,0,0,0,0)
CLASS_DEF(C4,0,0,1,0,0,0,0)
CLASS_DEF(C5,0,0,0,1,0,0,0)
CLASS_DEF(C6,0,0,0,0,1,0,0)
CLASS_DEF(C7,0,0,0,0,0,1,0)
CLASS_DEF(C8,0,0,0,0,0,0,1)

template<typename C>
void capability() {
    cout << is_constructible<C, int>::value << ", ";
    cout << is_destructible<C>::value << ", ";
    cout << is_constructible<C>::value << ", ";
    cout << is_copy_constructible<C>::value << ", ";
    cout << is_copy_assignable<C>::value << ", ";
    cout << is_move_constructible<C>::value << ", ";
    cout << is_move_assignable<C>::value;
    cout << endl;
}

int main() {
    capability<C1>();
    capability<C2>();
    capability<C3>();
    capability<C4>();
    capability<C5>();
    capability<C6>();
    capability<C7>();
    capability<C8>();
    return 0;
}
