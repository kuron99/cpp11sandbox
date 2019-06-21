#include <fstream>
#include <vector>
#include "boost/serialization/serialization.hpp"
#include "boost/archive/binary_oarchive.hpp"
#include "boost/archive/binary_iarchive.hpp"
#include "boost/serialization/vector.hpp"

using namespace boost::serialization;

class C1 {
    friend boost::serialization::access;
public:
    C1() = default;
    C1(int x, int y) : x_(x), y_(y) {}

    template <class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & x_;
        ar & y_;
    }
    int x() {return x_;}
    int y() {return y_;}

private:
    int x_;
    int y_;
};

static_assert(std::is_trivially_copyable_v<C1>);
static_assert(std::is_trivially_default_constructible_v<C1>);

int main() {
    std::vector<C1> vector;
    std::ofstream ofs("testfile.dat");

    vector.emplace_back(1,100);
    vector.emplace_back(2,200);
    vector.emplace_back(3,300);

    {
        boost::archive::binary_oarchive oa(ofs);
        oa << vector;
    }
    std::vector<C1> restored;
    {
       std::ifstream ifs("testfile.dat");
       boost::archive::binary_iarchive ia(ifs);
       ia >> restored;
    }
    assert(3 == restored.size());
    assert(100 == restored[0].y());
    assert(200 == restored[1].y());
    assert(300 == restored[2].y());
}