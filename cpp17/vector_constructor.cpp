// difference of calling constructor with {} and () - if it accepts initilizer_list, it's inclined to deduce the arg as il
// when passing initializer list to function, it's not always possible to infer the type depending on how the function is overload

#include <vector>
#include <cassert>
using namespace std;

int f1(vector<pair<int, int>> v) {
    return v.size();
}
int f1(vector<int> v) {
    return v.size();
}


int main() {
    vector<int> a{3};   // this is initializer list
    assert(a.size() != 3);

    vector<int> b(3); // not initializer list
    assert(b.size() == 3);

    vector<int> a2{{3}};   // arg can be passed within initializer list
    assert(a == a2);

    vector<pair<int, int>> c1{{1,2}, {3, 4}}; // initializer_list<pair>
    vector<pair<int, int>> c2{{{1,2}, {3, 4}}}; // additional {}
    assert(c1 == c2);

    vector<vector<pair<int, int>>> vv{{{1,2}}};
    assert(1 == f1(vector<pair<int,int>>{{1,2}}));  // need to specify vector<pair... because of ambiguity
}