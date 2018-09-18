// float and doubles are passed by xmm0, xmm1
// __int128 is passed by RDI and RSI, and returned with RAX and RDX
// MUL/IMUL instructions are used, the results are stored in RDX:RAX

int func1(double c1, int c2, float c3) {
    return c1 * c3 + c2;
}
__int128 func2(__int128 c4) {
    return c4 * c4 + 1;
}
int main() {
    int x = func1(1.1, 2, 3.3);
    int y = func2(1024);
    return x + y;
}


