// pointer traints allows pointer to get the element type
#include <memory>

class C1 {

};

int main() {
    std::unique_ptr<C1> pc{};
    static_assert(std::is_same_v<std::unique_ptr<C1>, std::pointer_traits<std::unique_ptr<C1>>::pointer>);
    static_assert(std::is_same_v<C1, std::pointer_traits<std::unique_ptr<C1>>::element_type>);
    static_assert(std::is_same_v<std::ptrdiff_t , std::pointer_traits<std::unique_ptr<C1>>::difference_type>);

    static_assert(std::is_same_v<std::shared_ptr<C1>, std::pointer_traits<std::shared_ptr<C1>>::pointer>);
    static_assert(std::is_same_v<C1, std::pointer_traits<std::shared_ptr<C1>>::element_type>);
    static_assert(std::is_same_v<std::ptrdiff_t , std::pointer_traits<std::shared_ptr<C1>>::difference_type>);

    static_assert(std::is_same_v<std::weak_ptr<C1>, std::pointer_traits<std::weak_ptr<C1>>::pointer>);
    static_assert(std::is_same_v<C1, std::pointer_traits<std::weak_ptr<C1>>::element_type>);
    static_assert(std::is_same_v<std::ptrdiff_t , std::pointer_traits<std::weak_ptr<C1>>::difference_type>);

    static_assert(std::is_same_v<C1*, std::pointer_traits<C1*>::pointer>);
    static_assert(std::is_same_v<C1, std::pointer_traits<C1*>::element_type>);
    static_assert(std::is_same_v<std::ptrdiff_t,  std::pointer_traits<C1*>::difference_type >);
}