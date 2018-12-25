// sol
#include <stdio.h>
void add(int, int, int *);
int main(void)
{
    //! showMemory(start=65520)
    int a, b, sum;
    printf("Please enter two integers: ");
    scanf("%d%d", &a, &b);
    add(a, b, &sum);
    printf("The sum of %d and %d is %d", a, b, sum);
    return 0;
}

void add(int x, int y, int *resultptr)
{
    int z = x + y;
    *resultptr = z;
}

// mS
#include <stdio.h>
void add(int *, int *, int *);
int main(void)
{
    //! showMemory(start=65520)
    int a, b, sum;
    printf("Please enter two integers: ");
    scanf("%d%d", &a, &b);
    add(&a, &b, &sum);
    printf("%d + %d = %d\n", a, b, sum);
    return 0;
}

void add(int *x, int *y, int *z)
{
    *z = *x + *y;
    printf("Added numbers in the function!\n");
}

// Please enter two integers: 23 7
// Added numbers in the function!
// 23 + 7 = 30