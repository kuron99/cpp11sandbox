// make_shared create a memory location at once for object body and shared_ptr control block.
// The control block comes lower address than object body.
// When object is aligned to cache lines, the control block is aligned to the boundary too.

#include <memory>
#include <iostream>
#include <cassert>

class alignas(64) C1 {

};

using type = C1;
using shared_ptr = std::shared_ptr<type>;

static_assert(sizeof(shared_ptr) == 16);

struct S {
    void * ptr_;
    void * control_block_;
};

void print_address(shared_ptr const& x) {
    S addr = *reinterpret_cast<S const*>(&x);
    assert(addr.ptr_ == x.get());
    std::cout << "address: " << std::hex << x.get() << " control block: " << addr.control_block_;
}
int main() {
    shared_ptr x = std::make_shared<type>();

    print_address(x);

}