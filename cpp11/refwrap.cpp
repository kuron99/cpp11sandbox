// refrence_wrapper holds lvalue reference and it can be reassigned - convenient to pass lvalue references around
// rvalue cannot be stored in reference_wrapper
// tuple can holds rvalue reference, but it doesn't prolong the temp. lifetime so the usage is very much limited

#include <functional>
#include <cassert>

class C1 {
public:
    C1(int x) : x_{x} {}

    C1(const C1 &) : x_(100) {}

    C1(C1 &&) : x_(200) {}

    int x_;

};

int main() {
    C1 c1{1};
    C1 &rc1{c1};
    std::reference_wrapper<C1> r{c1};
    assert(r.get().x_ == 1);
    assert(static_cast<C1&>(r).x_ == 1); // implicit cast from reference_wrapper to its element
    std::reference_wrapper<C1> r2{rc1};
    assert(r2.get().x_ == 1);

    C1 c2{2};
    r = c2;
    assert(r.get().x_ == 2);

//    std::reference_wrapper<C1> rwrvalue{C1{-2}}; // cannot store rvalue in reference_wrapper

    // tuples don't hold rvalues either, but hold values move constructed from rvalue
    std::tuple<C1> tuple = std::make_tuple(C1{3});
    assert(std::get<0>(tuple).x_ == 200);
    assert(std::get<0>(std::forward_as_tuple(C1{3})).x_ == 3); // forward_as_tuple() doesn't prolong the lifetime of temporaries

    auto reftuple = std::tuple<C1&>(c2);
    assert(std::get<0>(reftuple).x_ == 2);
    c2.x_ = 20;
    assert(std::get<0>(reftuple).x_ == 20);
    assert(std::get<0>(std::tuple<C1&&>(C1{4})).x_ == 4); // tuple can be created, but the temporaries lifetime not prolonged
    return 0;
}
