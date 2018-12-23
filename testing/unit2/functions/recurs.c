// factorial
#include <stdio.h>
// 5! = 1*2*3*4*5
// n! = 1*2*3*...*(n-1)*n
int main(void)
{
    int n, facto, i;
    printf("Please enter a positive integer: ");
    scanf("%d", &n);
    facto = 1;
    for (i = 1; i <= n; i++)
    {
        facto = i * facto;
    }
    if (n < 0)
    {
        printf("%d is negative! Aborting..\n", n);
    }
    else
    {
        printf("%d! = %d.\n", n, facto);
    }
    return 0;
}

// recursion
// Fibonacci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
int fibonacci(int);
#include <stdio.h>
int main(void)
{
    //! showMemory(start=65520)
    int N, fib;
    printf("Which Fibonacci number would you like: ");
    scanf("%d", &N);
    if (N <= 0)
    {
        printf("%d is not positive. Aborting!\n", N);
    }
    else
    {
        fib = fibonacci(N);
        printf("The %dth Fibonacci number is %d.\n", N, fib);
    }
    return 0;
}

int fibonacci(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}

// compute the sum of the digits of a number.
// Examples
// Input
// 47253
// Output
// 21
#include <stdio.h>
int sumOfDigits(int);
int main(void)
{
    int i, sum;
    scanf("%d", &i);
    sum = sumOfDigits(i);
    printf("%d", sum);
    return 0;
}
int sumOfDigits(int a)
{
    if (a < 10)
        return a;
    else
        return (a % 10 + sumOfDigits(a / 10));
}