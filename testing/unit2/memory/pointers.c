// visualize in memory the concept of a pointer
// use pointers to pass variables by reference to functions
// perform simple pointer arithmetic
// demonstrate that an array name is a pointer by performing pointer arithmetic
// create functions to which arrays can be passed and that can modify arrays

// Get and print the address of a variable using pointers
#include <stdio.h>
int main()
{
    //! showMemory(start=65520)
    int a = 42;
    double d = 58.394;
    char c = 'r';
    int *addressOfA = &a;
    printf("address of a: %p\n", addressOfA);
    double *addressOfD = &d;
    printf("address of d: %p\n", addressOfD);
    char *addressOfC = &c;
    printf("address of c: %p\n", addressOfC);
    return 0;
}

// Dereference a pointer: get the value stored at a specific address
#include <stdio.h>
int main()
{
    //! showMemory(start=65520)
    double a = 42.98;
    double *addressOfA = &a;
    printf("At the address %p there is the value %.2lf\n", addressOfA, *addressOfA);
    char c = 'm';
    char *addressOfC = &c;
    char d = *addressOfC;
    *addressOfA = 32;
    *addressOfA = *addressOfA + 1;
    printf("At the address %p there is the value %.2lf\n", addressOfA, *addressOfA);
    return 0;
}