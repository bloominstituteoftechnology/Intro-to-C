// Pass pointers to functions
#include <stdio.h>
void timesTwo(int *);
int main(void)
{
    //! showMemory(start=65520)
    int n;
    printf("Please enter an integer: ");
    scanf("%d", &n);
    printf("In main: You entered %d.\n", n);
    timesTwo(&n);
    printf("In main: The value of n is %d.\n", n);
    return 0;
}

void timesTwo(int *numptr)
{
    printf("In the function: the number is %d.\n", *numptr);
    *numptr = *numptr * 2;
    printf("In the function: the new number is %d.\n", *numptr);
}

// Please enter an integer: 7
// In main: You entered 7.
// In the function: the number is 7.
// In the function: the new number is 14.
// In main: The value of n is 14.