// enum class count from 0 even some members has = 0

enum class e1 : int {
    a,
    b,
    c = 0,
    d,
    e
};

static_assert(static_cast<int>(e1::a) == 0);
static_assert(static_cast<int>(e1::b) == 1);
static_assert(static_cast<int>(e1::c) == 0);