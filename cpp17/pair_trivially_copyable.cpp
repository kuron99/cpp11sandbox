// pair/tuple of trivially copyables are not always trivially copyable
// while C++17 ensures same for trivially destructiveness

#include <type_traits>
#include <tuple>

struct C1 {
    int x;
    int y;
};

static_assert(std::is_trivially_copyable_v<C1>);
static_assert(std::is_trivially_destructible_v<C1>);
static_assert(!std::is_trivially_copyable_v<std::pair<C1, C1>>);
static_assert(std::is_trivially_destructible_v<std::pair<C1, C1>>);
static_assert(!std::is_trivially_copyable_v<std::tuple<C1, C1, C1>>);
static_assert(std::is_trivially_destructible_v<std::tuple<C1, C1, C1>>);
