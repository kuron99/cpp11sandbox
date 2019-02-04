
#include <any>
#include <memory>
#include <tuple>
#include <optional>
#include <vector>
#include <string>
#include <string_view>
#include <iostream>
#include <bits/stdc++.h>

int main() {

    std::cout << "sizeof(std::any) : " << sizeof(std::any) << std::endl;
    std::cout << "sizeof(std::vector<int32_t>) : " << sizeof(std::vector<int32_t>) << std::endl;
    std::cout << "sizeof(std::vector<int64_t>) : " << sizeof(std::vector<int64_t>) << std::endl;
    std::cout << "sizeof(std::array<int64_t, 3>) : " << sizeof(std::array<int64_t, 3>) << std::endl;
    std::cout << "sizeof(std::array<int64_t, 6>) : " << sizeof(std::array<int64_t, 6>) << std::endl;
    std::cout << "sizeof(std::unique_ptr<int32_t>) : " << sizeof(std::unique_ptr<int32_t>) << std::endl;
    std::cout << "sizeof(std::shared_ptr<int32_t>) : " << sizeof(std::shared_ptr<int32_t>) << std::endl;
    std::cout << "sizeof(std::string) : " << sizeof(std::string) << std::endl;
    std::cout << "sizeof(std::string_view) : " << sizeof(std::string_view) << std::endl;
    std::cout << "sizeof(std::optional<int16_t>) : " << sizeof(std::optional<int16_t>) << std::endl;
    std::cout << "sizeof(std::optional<int32_t>) : " << sizeof(std::optional<int32_t>) << std::endl;
    std::cout << "sizeof(std::optional<int64_t>) : " << sizeof(std::optional<int64_t>) << std::endl;
    std::cout << "sizeof(__int128) : " << sizeof(__int128) << std::endl;
    std::cout << "sizeof(std::optional<__int128>) : " << sizeof(std::optional<__int128>) << std::endl;
    std::cout << "sizeof(std::tuple<int32_t>) : " << sizeof(std::tuple<int32_t>) << std::endl;
    std::cout << "sizeof(std::tuple<int64_t>) : " << sizeof(std::tuple<int64_t>) << std::endl;
    std::cout << "sizeof(std::tuple<int64_t, int64_t>) : " << sizeof(std::tuple<int64_t, int64_t>) << std::endl;
    std::cout << "sizeof(std::tuple<int64_t, int64_t, int64_t>) : " << sizeof(std::tuple<int64_t, int64_t, int64_t>) << std::endl;

    std::cout << "sizeof(void*) : " << sizeof(void*) << std::endl;
    std::cout << "sizeof(char[6]) : " << sizeof(char[6]) << std::endl;
}