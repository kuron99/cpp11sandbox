// private membmer variable can be accessed by using pointer to member

#include <iostream>

template <class Tag>
struct stowed
{
    static typename Tag::type value;
};
template <class Tag>
typename Tag::type stowed<Tag>::value;

template <class Tag, typename Tag::type x>
struct stow_private
{
    stow_private() { stowed<Tag>::value = x; }
    static stow_private instance;
};
template <class Tag, typename Tag::type x>
stow_private<Tag,x> stow_private<Tag,x>::instance;

struct A
{
    A() : x("proof!") {}
private:
    char const* x;
};

struct A_x { typedef char const*(A::*type); };
template class stow_private<A_x,&A::x>;

int main()
{
    A a;

    std::cout << a.*stowed<A_x>::value << std::endl;
};
