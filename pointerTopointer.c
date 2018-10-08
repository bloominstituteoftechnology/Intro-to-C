#include <stdio.h>
int main()
{
    int x = 5;
    int *p = &x;
    *p = 6;
    int **q = &p;
    int ***r = &q;
    printf("%d\n", *p); // 6
    // printf("%d\n", p);     // address of p
    printf("%d\n", *q);    // value at address stored in q => address of p
    printf("%d\n", *(*q)); // value at address stored in p => value of p => 6
    // printf("%d\n", **q);   // same as above
    // printf("%d\n", *r);       // address of q
    printf("%d\n", *(*r));    //  *r value in q (which is p)
    printf("%d\n", *(*(*r))); // value of q - which is address of p
    // printf("%d\n", *(*q)); // value at address stored in p => value of p => 6
    ***r = 10;
    printf("%d\n", x); // 10
    **q = *p + 2;
    printf("%d\n", x); // 12
}