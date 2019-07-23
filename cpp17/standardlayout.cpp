// standard layout is one of the conditions for compatibility with C struct
// - different access specifiers
// - inherit and define members of their own
// - virtual functions
// - virtual inheritance

#include <type_traits>
#include <memory>
#include <any>
#include <optional>
#include <variant>
#include <vector>
#include <functional>
#include <sstream>

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


class NonStandard {
    int x_{};
public:
    int y_{};
};
static_assert(std::is_standard_layout_v<std::string>);
static_assert(std::is_standard_layout_v<std::string_view>);
static_assert(std::is_standard_layout_v<std::unique_ptr<int>>);
static_assert(std::is_standard_layout_v<std::unique_ptr<NonStandard>>);
static_assert(std::is_standard_layout_v<std::shared_ptr<int>>);
static_assert(std::is_standard_layout_v<std::weak_ptr<int>>);
static_assert(std::is_standard_layout_v<std::any>);
static_assert(std::is_standard_layout_v<std::optional<int>>);
static_assert(! std::is_standard_layout_v<std::optional<NonStandard>>);
static_assert(std::is_standard_layout_v<std::variant<int>>);
static_assert(std::is_standard_layout_v<std::variant<int, int>>);
static_assert(std::is_standard_layout_v<std::pair<int, int>>);
static_assert(! std::is_standard_layout_v<std::pair<NonStandard, NonStandard>>);
static_assert(std::is_standard_layout_v<std::tuple<int>>);
static_assert(! std::is_standard_layout_v<std::tuple<NonStandard>>);
static_assert(! std::is_standard_layout_v<std::tuple<int, int>>);
static_assert(! std::is_standard_layout_v<std::tuple<int, int, int>>);
static_assert(std::is_standard_layout_v<std::vector<int>>);
static_assert(std::is_standard_layout_v<std::vector<NonStandard>>);
static_assert(! std::is_standard_layout_v<std::function<int(int)>>);
static_assert(! std::is_standard_layout_v<std::stringstream>);

