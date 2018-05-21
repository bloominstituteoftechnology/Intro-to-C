#include <stdio.h>

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

    int counter = 0;
    for (int num = 0; num <= n; num++) // #QUESTION: Why does it seem to not matter whether num initial is 0 or 1?
    {
        if (num % 3 == 0 && num % 5 == 0)
        {
            printf("%sFizzBuzz\n"); // %s indicates: "this is a type string"
        }
        else if (num % 3 == 0)
        {
            printf("%sFizz\n");
        }
        else if (num % 5 == 0)
        {
            printf("%sBuzz\n");
        }
        else
        {
            counter = counter + 1;
            // printf("Counter is: %c\n", counter); // #QUESTION: Why does this not work as expected?
        };
    }
    return counter;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
