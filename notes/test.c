// #include <stdio.h>

// int main()
// {
//     int a;
//     int *p;
//     a = 10;
//     p = &a;                     // &a - address of a
//     printf("pointer, %d\n", p); // address of a (long number)
//     // printf("value of a, %d\n", *p);   // 10
//     // printf("address of a, %d\n", &a); // same address, as p points to the same adress
//     // printf("address of p, %d\n", &p); // address of (different)

//     // ************************************************
//     // to modife value of 'a' using the pointer 'p'
//     // dereferencing
//     // printf("a = %d\n", a); // for checking purpose
//     // *p = 12;               // value at address being pointed by 'p' is now 12
//     // printf("a= %d\n", a);  // 12

//     // ************************************************
//     printf("Address of P before is %d\n", p); // same as address of a
//     printf("Value of P before is %d\n", *p);  // 10
//     int b = 20;
//     *p = b;                                  // only changing the value of a pointer p
//     printf("Address of P after is %d\n", p); // the same as a
//     printf("Value of P after is %d\n", *p);  // 10

//     // ********************************************
//     // int a;
//     // int *p;
//     // a = 10;
//     // p = &a;
//     // these four line can written as:
//     int a = 10;
//     int *p = &a;
// }

// *********** Pointer Arithmetic *************
#include <stdio.h>

int main()
{
    int a = 10;
    int *p;
    p = &a;

    printf("address a is %d\n", &a);
    printf("address p is %d\n", p);                       // if p points to 2002
    printf("value at address p is %d\n", *p);             // 10
    printf("size of integer is %d bytes\n", sizeof(int)); // 'sizeof' of integer is 4 bytes
    printf("address p+1 is %d\n", p + 1);                 // next address will 2006 (skipping 4 bytes)
    printf("value at address after p+1 is %d\n", *p);     // 10
    printf("value at address (p+1) is %d\n", *(p + 1));   // garbage number - we do not have an integer allocated to this particular memory address
    printf("address p+2 is %d\n", p + 2);                 // next address will 2010 (skipping 8 bytes)
    printf("value at address p+2 is %d\n", *p);           // 10
    // values
}