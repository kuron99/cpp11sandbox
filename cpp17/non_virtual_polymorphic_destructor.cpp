// what happens to polymorphic class with non virtual destructor?

class C1 {
public:
    C1() = default;

protected:
//    ~C1() {
//        x_ = 0;
//    };
    ~C1() = default;
private:
    int x_{};
    int y_{};
};

class C2 : public C1 {
public:
    C2() = default;
    ~C2() {
    };

};
int main() {
    C2 c{};
}