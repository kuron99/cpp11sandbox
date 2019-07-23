// standard layout is one of the conditions for compatibility with C struct
// - different access specifiers
// - inherit and define members of their own
// - virtual functions
// - virtual inheritance

#include <type_traits>

class Empty {

};
static_assert(std::is_standard_layout_v<Empty>);

class C1 {
public:
    int x_;
};
static_assert(std::is_standard_layout_v<C1>);

class PublicAndPrivateMembers {
    int x_;
public:
    int y_;
};
static_assert(! std::is_standard_layout_v<PublicAndPrivateMembers>);

class Inherit : public C1 {
public:
};
static_assert(std::is_standard_layout_v<Inherit>);
class InheritEmpty : public Empty {
public:
    int y_;
};
static_assert(std::is_standard_layout_v<InheritEmpty>);

class InheritAndDefineOwnMember : public C1 {
public:
    int y_;
};
static_assert(! std::is_standard_layout_v<InheritAndDefineOwnMember>);

class VirtualFunc {
    virtual ~VirtualFunc() = default;
};
static_assert(! std::is_standard_layout_v<VirtualFunc>);

class InheritVirtual : public virtual C1 {
public:
    int y_;
};
static_assert(! std::is_standard_layout_v<InheritVirtual>);

class StandardLayoutMember {
    C1 c1_{};
    int y_;
};
static_assert(std::is_standard_layout_v<StandardLayoutMember>);

