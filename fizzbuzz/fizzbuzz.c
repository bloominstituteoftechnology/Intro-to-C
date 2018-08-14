#include <stdio.h>

/*
    Your fizzbuzz implementation should initialize a counter, then
    iterate n times. If the ith iteration is divisible by 3, print
    "Fizz". If it's divisible by 5, print "Buzz". If it's divisible
    by both 3 and 5, print "FizzBuzz". Increment the counter variable
    every time that nothing gets printed and return the counter.
    Don't forget to include newlines '\n' in your printf statements!
*/
int fizzbuzz(int n) // fizzbuzz function receives int n as an argument, returns int
{
    int counter = 0; // initialize counter

    for (int i = 1; i <= n; i++) // for loop to interate n times
    {
        if (i % 3 == 0 && i % 5 != 0) // displays "Fizz" if the ith number is a multiple of 3 but not of 5
        {
            printf("Fizz\n");
        }
        else if (i % 3 != 0 && i % 5 == 0) // displays "Buzz" if the ith number is a multiple of 5 but not of 3
        {
            printf("Buzz\n");
        }
        else if (i % 3 == 0 && i % 5 == 0) // displays "FizzBuzz" if the ith number is a multiple of 3 and 5
        {
            printf("FizzBuzz\n");
        }
        else
        {
            counter++; // add 1 to the counter at each iteration
        }
    }
    return counter; // return counter after the  iteration is finished
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
