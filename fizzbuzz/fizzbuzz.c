#include <stdio.h>
#include <stdlib.h>

/*
    Your fizzbuzz implementation should initialize a counter, then
    iterate n times. If the ith iteration is divisible by 3, print
    "Fizz". If it's divisible by 5, print "Buzz". If it's divisible
    by both 3 and 5, print "FizzBuzz". Increment the counter variable
    every time that nothing gets printed and return the counter.
    Don't forget to include newlines '\n' in your printf statements!
*/
int fizzbuzz(int n)
{
    printf("\n\N %d\n\n", n);
    int counter = 0;
    for (int i = 1; i <= n; ++i)
    {
        i % 3 == 0 ? i % 5 == 0 ? printf("FizzBuzz\n") : printf("Fizz\n") : i % 5 == 0 ? i % 3 == 0 ? printf("FizzBuzz %d\n", i) : printf("Buzz") : counter++;
    }
    printf("\n\COUNTER %d\n\n", counter);
    return counter;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
