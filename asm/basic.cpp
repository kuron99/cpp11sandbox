// basic asm convention
//  functions start with:
//    push rbp
//    mov rbp, rsp
//  and end with:
//    pop rbp
//    ret

int f1() {
    return -1;
}
int main() {
    return f1();
}
