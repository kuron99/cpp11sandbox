// gcc shows correct level such as 7.4.0
// clang shows little bit old one such as 4.2.1

#include <stdio.h>
#define __TBB_GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

int main() {
    printf("__GNUC__ : %d", __GNUC__);
    printf("__GNUC_MINOR__ : %d", __GNUC_MINOR__);
    printf("__GNUC_PATCHLEVEL__) : %d",__GNUC_PATCHLEVEL__);
}
