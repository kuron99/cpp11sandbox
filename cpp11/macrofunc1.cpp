// to nest macro function definition, CONCAT should be defined and used

#if 1
#define CONCAT(x, y) x ## y
#define IIF(x) CONCAT(IIF_,x)
#else
#define IIF(x) IIF_ ## x
#endif
#define IIF_0(t, f) f
#define IIF_1(t, f) t
#define A(x) 1

int main() {
    int IIF(0) (a, b);
    int IIF(1) (c, d);
    int IIF(A()) (x, y);
}
