// playing around with alignment

#include <cstdio>

struct S1 {
    short s;
    unsigned char uc[3];
};

struct S2 {
    char string[10];
    unsigned char uc;
};

struct S3 {
    double d;
    long long ll;
    char c;
};

typedef union U {
    char string[17];
    double d[2];
} U_t;

static const char format[] = "sizeof(%s)=%lu, AlignmentOf(%s)=%lu.\n";

#define PrintSizeAndAlignment(type) std::printf(format, #type, (unsigned long)sizeof(type), #type, (unsigned long)alignof(type))

int main(void)
{
    PrintSizeAndAlignment(char);
    PrintSizeAndAlignment(unsigned char);
    PrintSizeAndAlignment(short);
    PrintSizeAndAlignment(unsigned short);
    PrintSizeAndAlignment(int);
    PrintSizeAndAlignment(unsigned int);
    PrintSizeAndAlignment(long);
    PrintSizeAndAlignment(unsigned long);
    PrintSizeAndAlignment(long long);
    PrintSizeAndAlignment(unsigned long long);
    printf("\n");

    PrintSizeAndAlignment(float);
    PrintSizeAndAlignment(double);
    PrintSizeAndAlignment(long double);
    printf("\n");

    PrintSizeAndAlignment(struct S1);
    PrintSizeAndAlignment(struct S2);
    PrintSizeAndAlignment(struct S3);
    PrintSizeAndAlignment(union U);

    return 0;
}