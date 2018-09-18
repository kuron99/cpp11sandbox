// asm study about function call
// - on x86_64, top 6 parameters are passed by registers and the rest are passed on stack
// - each function forms a stack frame, which stores passed parameters and local variables
// - RBP register indicates the base point in the middle of the stack frame, as shown in the figure 3.3 of the ABI doc:
// https://software.intel.com/sites/default/files/article/402129/mpx-linux64-abi.pdf

int f1(int x) {
    return x + x;
}

int square(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9, int c10) {
    int x = f1(c9);
    return c1 * c1 + c10 + x;
}

int main() {
    int s = square(1,2,3,4,5,6,7,8,9,10);
    s++;
}
