// sample to create map from initializer

#include <unordered_map>
#include <vector>
int main() {

    std::unordered_map<std::string, std::vector<int>> map;
    map = {

                 {
                              "A", {1, 2, 3}
                 }

    };

}