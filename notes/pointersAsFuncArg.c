#include <stdio.h>
void Increment(int *p) // call by reference
{
    *p = (*p) + 1;
    printf("value of pointer (address of a) in increment is = %d\n", p);
    printf("value of a pointer address in increment is = %d\n", *p);
}
int main()
{
    int a; // local var
    a = 10;
    Increment(&a);
    printf("address of var 'a' in main is = %d\n", &a);
    printf("a = %d\n", a);
}

// void Increment(int a) // call by value doesn't work
// {
//     a = a + 1;

//     printf("value of var 'a' in increment is = %d\n", a);
//     printf("address of var 'a' in increment is = %d\n", &a);
// }