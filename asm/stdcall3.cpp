// experiment how class variable is passed
// - constructor has hidden first arg "this"
// - class are passed on multiple registers when passed by value
//   C1 size is 12 bytes, so it spans, e.g. rsi and rdx
// - C1& is actually passed as pointer

class C1 {
public:
    C1(int x, int y) : x_(x), y_(y) {}
    int x_;
private:
    int y_ = 2;
    int z_ = 3;
};
int func1(int c1, C1 c2, C1& c3, C1* c4) {
    return c1 * c3.x_ + c2.x_ + c4->x_;
}
int main() {
    C1 c1{1, 2};
    return func1(9, c1, c1, &c1);
}


