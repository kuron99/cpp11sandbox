#include <vector>

class C1;

class A1 {
public:
    A1() = default;
    A1(std::vector<C1> elements) noexcept : elements_(std::move(elements)) {}  // NOLINT
    std::vector<C1> const& elements() const noexcept { return elements_; }
    std::size_t size() const noexcept { return elements_.size(); }
private:
    std::vector<C1> elements_ {};
    C1 c1;
};

//std::size_t f2() {
//    C1 c1;
//    std::vector<C1> elements_ {};
//    return elements_.size();
//}

int main() {
//    A1 c1{};

}
class C1 {};
