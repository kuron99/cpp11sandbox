// unordered_map has default max load factor 1 and bucket count 1

#include <unordered_map>
#include <cassert>
#include <string>

int main() {
    std::unordered_map<std::int64_t, std::string> map{};

    assert(1 == map.max_load_factor());
    assert(1 == map.bucket_count()) ;

}