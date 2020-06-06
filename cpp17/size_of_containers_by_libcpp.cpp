#include <ciso646>
#ifdef _LIBCPP_VERSION

#include <any>
#include <memory>
#include <tuple>
#include <optional>
#include <vector>
#include <string>
#include <string_view>
#include <iostream>
#include <variant>
#include <boost/multiprecision/cpp_int.hpp>


int main() {
    static_assert(sizeof(std::vector<int32_t>) == 24); // 3 ptrs (start, finish, end_of_stg)
    static_assert(sizeof(std::vector<int64_t>) == 24);
    static_assert(sizeof(std::array<int64_t, 3>) == 24);
    static_assert(sizeof(std::array<int64_t, 6>) == 48);
    static_assert(sizeof(std::array<int32_t, 3>) == 12);
    static_assert(sizeof(std::array<int32_t, 6>) == 24);
    static_assert(sizeof(std::unique_ptr<int32_t>) == 8);
    static_assert(sizeof(std::shared_ptr<int32_t>) == 16); // ptr + ptr to control block
    static_assert(sizeof(std::string) == 24); // SSO (16 char buffer + data length + data ptr(not used?)), non-SSO (capacity(16bytes) + data length + data ptr)
    static_assert(alignof(std::string) == 8);
    static_assert(sizeof(std::string_view) == 16); // ptr + len
    static_assert(sizeof(std::optional<int16_t>) == 4); // int16 + bool
    static_assert(alignof(std::optional<int16_t>) == 2);
    static_assert(sizeof(std::optional<int32_t>) == 8); // int32 + bool
    static_assert(alignof(std::optional<int32_t>) == 4);
    static_assert(sizeof(std::optional<int64_t>) == 16); // int64 + bool
    static_assert(alignof(std::optional<int64_t>) == 8);
    static_assert(sizeof(std::optional<__int128>) == 32); // int128 + bool
    static_assert(alignof(std::optional<__int128>) == 16);
    static_assert(sizeof(__int128) == 16);
    static_assert(sizeof(std::optional<std::string>) == 32); // string + bool
    static_assert(sizeof(std::optional<std::string_view>) == 24); // string_view + bool
    static_assert(sizeof(std::tuple<int32_t>) == 4);
    static_assert(sizeof(std::tuple<int64_t>) == 8);
    static_assert(sizeof(std::tuple<int64_t, int64_t>) == 16);
    static_assert(sizeof(std::tuple<int64_t, int64_t, int64_t>) == 24);
    static_assert(alignof(std::tuple<int64_t, int64_t, int64_t>) == 8);

    static_assert(sizeof(std::any) == 32); // SSO (data 8 bytes + ptr to manager) or non-SSO (ptr to data + ptr to manager)
    static_assert(alignof(std::any) == 8);
    static_assert(sizeof(std::variant<int32_t>) == 8);
    static_assert(sizeof(std::variant<int32_t, int64_t>) == 16);
    static_assert(sizeof(std::variant<int32_t, int64_t, float>) == 16);
    static_assert(sizeof(std::variant<int32_t, int64_t, float, double>) == 16);
    static_assert(sizeof(std::variant<int64_t>) == 16);
    static_assert(sizeof(std::variant<std::string>) == 32);
    static_assert(sizeof(std::variant<int64_t, std::string>) == 32);
    static_assert(sizeof(std::function<std::int64_t(std::int64_t)>) == 48); // ptr to function, invoker, manager + ?
    static_assert(alignof(std::function<std::int64_t(std::int64_t)>) == 16);

    static_assert(sizeof(void*) == 8);
    static_assert(sizeof(char[6]) == 6);

    static_assert(sizeof(std::mutex) == 40);
    static_assert(sizeof(std::condition_variable) == 48);

    static_assert(sizeof(std::atomic<std::int32_t>) == 4);
    static_assert(sizeof(std::atomic<std::int64_t>) == 8);
    static_assert(sizeof(std::atomic<double>) == 8);
}

#endif // _LIBCPP_VERSION