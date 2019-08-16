
class X;              // X is an incomplete type
extern X* xp;         // xp is a pointer to an incomplete type

void foo() {
    xp++;               // ill-formed: X is incomplete
}

struct X { int i; };  // now X is a complete type

X x;
void bar() {
    xp = &x;            // OK: type is “pointer to X”
    xp++;               // OK: X is complete
}

int main() {
    
}