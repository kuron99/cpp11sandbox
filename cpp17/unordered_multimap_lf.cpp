// unordered_map behavior

#include <unordered_map>
#include <cassert>
#include <iostream>

bool compare(double a, double b) {
    return std::abs(a - b ) < 0.01;
}

int main() {
    {
        std::unordered_multimap<std::int64_t, std::int64_t> map{};

        assert(compare(0.0 , map.load_factor()));  // lf = 0
        assert(compare(1.0 , map.max_load_factor()));
        assert(1 == map.bucket_count()) ;         // initially only one bucket
        map.reserve(1); // rehash happens

        assert(2 == map.bucket_count()) ;
        map.emplace(1,0);  // no rehash happens
        assert(compare(0.5 , map.load_factor()));

        map.emplace(1,1); // rehash happens 2 buckets -> 5 buckets
        assert(compare(0.4 , map.load_factor())); // multimap treats inserting same key as hash collision
        assert(5 == map.bucket_count()) ;
        assert(compare(1.0 , map.max_load_factor()));
        assert(2 == map.bucket_size(map.bucket(1))) ; // size of bucket can be accessed via bucket index
    }
    {
        std::unordered_multimap<std::int64_t, std::int64_t> map{};
        map.max_load_factor(2.0);
        map.reserve(10);

        assert(5 <= map.bucket_count()) ;
        std::cout << "bucket count : " << map.bucket_count() << std::endl;
        map.reserve(20);
        assert(10 <= map.bucket_count()) ;
        std::cout << "bucket count : " << map.bucket_count() << std::endl;
    }

}