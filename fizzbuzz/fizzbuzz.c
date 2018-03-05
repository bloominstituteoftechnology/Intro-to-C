#include <stdio.h>

/*
    Your fizzbuzz implementation should initialize a counter, then
    iterate n times. If the ith iteration is divisible by 3, print
    "Fizz". If it's divisible by 5, print "Buzz". If it's divisible
    by both 3 and 5, print "FizzBuzz". Increment the counter variable
    every time that nothing gets printed and return the counter.
*/

int fizzbuzz(int n);

int fizzbuzz(int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            ++i;
        };
        if (i % 3 == 0 && i % 5 == 0)
        {
            printf("FizzBuzz\n");
        };
        if (i % 3 == 0)
        {
            printf("Fizz\n");
        };
        if (i % 5 == 0)
        {
            printf("Buzz\n");
        };
    }

    return 0;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    // printf("The result is: %d\n", finalResult);

    return 0;
}
#endif