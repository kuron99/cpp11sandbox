// how to calculate offset of std::tuple<Types...>

#include <tuple>
#include <cassert>
#include <vector>

template <std::size_t I, class ...Types>
std::size_t diff(std::tuple<Types...>& entity) {
    return (char*)std::addressof(std::get<I>(entity)) - (char*)std::addressof(entity);
}

template <class ...Types, size_t ... Is>
std::vector<std::size_t> offsets(std::tuple<Types...>& entity, std::index_sequence<Is...>) {
    return {diff<Is>(entity)...};
}

template <class ...Types>
std::vector<std::size_t> offsets(std::tuple<Types...>& entity) {
    return offsets<Types...>(entity, std::make_index_sequence<sizeof...(Types)>());
}

int main() {
    std::tuple<int, long> t{};

    std::vector<std::size_t> v{offsets(t)};
    assert(8 == v[0]);
    assert(0 == v[1]);
}