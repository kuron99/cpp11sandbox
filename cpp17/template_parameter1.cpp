// playing around template template parameters
// template template parameter allow providing child parameter separately

#include <vector>

template <int N>
class C1 {
public:
    char buf[N];
};

template <template<int N> typename C, int M>
class C2 : public C<M> {
};

template <template<int N> typename C, int M>
class C3 {
    std::vector<C<M>> vector_{};
public:
    template<typename T>
    void add(T c) {
        vector_.emplace_back(c);
    }
};

int main() {
    // C1's parameter can be passed as one for C2
    static_assert(sizeof(C2<C1, 5>) == 5);
    static_assert(sizeof(C2<C1, 10>) == 10);

    C1<5> c1{};
    C3<C1, 5> test;
    test.add(c1);

    return 0;
}
