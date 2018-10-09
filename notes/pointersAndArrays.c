#include <stdio.h>
int main()
{
    int A[] = {2, 4, 5, 8, 1};

    // **** same address ****
    printf("%d\n", A);       // address of A ~ 200
    printf("%d\n", &A);      // address of A ~ 200
    printf("%d\n", &A[0]);   // address of A ~ 200
    printf("%d\n", (A + 1)); // address of A ~ 204
    printf("%d\n", (A + 2)); // address of A ~ 208
    printf("%d\n", (A + 3)); // address of A ~ 212
    printf("%d\n", (A + 4)); // address of A ~ 214

    // **** value ****
    printf("%d\n", A[0]); // value of A[0] ~ 200
    printf("%d\n", *A);   // value of A[0] ~ 200

    // using loop
    int i;
    int *p = A;
    // A++; // invalid
    p++; // valid
    for (i = 0; i < 5; i++)
    {
        printf("Address = %d\n", &A[i]);
        printf("Address = %d\n", A + i);
        printf("value = %d\n", A[i]);
        printf("value = %d\n", *(A + i));
    }
}