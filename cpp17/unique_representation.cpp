#include <type_traits>
#include <cstdint>
#include <tuple>
#include <vector>
#include <map>
#include <any>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <variant>
#include <bitset>

class C1 {
    int x_;
    int y_;
};

class Padding {
    std::int32_t x_;
    std::int64_t y_;
    std::int32_t z_;
};

int main() {
    static_assert(std::has_unique_object_representations_v<char>);
    static_assert(std::has_unique_object_representations_v<int>);
    static_assert(std::has_unique_object_representations_v<std::int32_t>);
    static_assert(std::has_unique_object_representations_v<std::int64_t>);
    static_assert(std::has_unique_object_representations_v<__int128>);
    static_assert(std::has_unique_object_representations_v<unsigned int>);

    // class with padding is not unique
    static_assert(std::has_unique_object_representations_v<C1>);
    static_assert(not std::has_unique_object_representations_v<Padding>);

    // floating point numbers are not unique, why?
    static_assert(not std::has_unique_object_representations_v<float>);
    static_assert(not std::has_unique_object_representations_v<double>);
    static_assert(not std::has_unique_object_representations_v<long double>);

    // pairs are not unique, why?
    static_assert(not std::has_unique_object_representations_v<std::pair<int, int>>);
    static_assert(not std::has_unique_object_representations_v<std::tuple<int, int, int>>);
    static_assert(not std::has_unique_object_representations_v<std::variant<int, int, int>>);

    // STL containers are mostly not unique
    static_assert(not std::has_unique_object_representations_v<std::vector<int>>);
    static_assert(not std::has_unique_object_representations_v<std::map<int, int>>);
    static_assert(not std::has_unique_object_representations_v<std::set<int>>);
    static_assert(not std::has_unique_object_representations_v<std::unordered_map<int, int>>);
    static_assert(not std::has_unique_object_representations_v<std::unordered_set<int>>);

    static_assert(not std::has_unique_object_representations_v<std::any>);
    static_assert(not std::has_unique_object_representations_v<std::function<void(void)>>);

    // bitset is unique
    static_assert(std::has_unique_object_representations_v<std::bitset<100>>);
}