#include <stdio.h>

int main(void)

{
    unsigned char x =12;
    unsigned char *p =&x;
    printf("x: %u\n", x);
    printf("at p: %u\n", *p);
    *p = 15;
    printf("x is: %u\n", x);
    return 0;
}