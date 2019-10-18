// trying to see when rehash() happens with unordered map/multimap

#include <random>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <iostream>

using namespace std::string_literals;

const static std::size_t NUM_WORDS = 100'000'000;
const static std::size_t NUM_DICTIONARY_WORDS = 150'000;

static int word_count(std::vector<std::string> const& in, std::unordered_multimap<std::string, std::size_t>& out) {
    for(auto && w : in) {
        out.emplace(std::move(w), 1);
    }
    return out.size();
}

std::mt19937 dict_random{};
static void random_word(std::string& out) {
    out.clear();
    for(int i=0; i < 10; i++) {
        out.append(std::string(1, 'a'+(dict_random() % 26)));
    }
}

int main() {
    std::vector<std::string> dictionary{};
    dictionary.reserve(NUM_DICTIONARY_WORDS);
    std::string tmp{};
    for(std::size_t i = 0; i < NUM_DICTIONARY_WORDS; ++i) {
        random_word(tmp);
        dictionary.emplace_back(std::move(tmp));
    }
    std::mt19937 mt{};
    std::vector<std::string> words{};
    words.reserve(NUM_WORDS);
    for(std::size_t i = 0; i < NUM_WORDS; ++i) {
        words.emplace_back(dictionary[mt() % dictionary.size()]);
    }
    std::unordered_multimap<std::string, std::size_t> map{};
    map.reserve(NUM_WORDS);

    {
        auto start = std::chrono::high_resolution_clock::now();
        word_count(words, map);
        auto end = std::chrono::high_resolution_clock::now();

        auto elapsed_seconds =
                std::chrono::duration_cast<std::chrono::duration<double>>(
                        end - start);

        std::cout << "elapsed secs: " << elapsed_seconds.count() << std::endl;
    }
    std::cout << map.size() << std::endl;
    for (auto& [k, v] : map) {
        std::cout << k << " : " << v << std::endl;
    }

}
