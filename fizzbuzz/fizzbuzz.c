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
    int counter = 0;            //initialize a counter
    for (int i = 0; i < n; i++) //iterate n times
    {
        if (i % 3 == 0) // if the ith iteration is divisible by 3, print "Fizz"
        {
            printf("Fizz\n");
        }
        else if (i % 5 == 0) // if the ith iteration is divisible by 5, print "Fizz"
        {
            printf("Buzz\n");
        }
        else if (i % 3 == 0 && i % 5 == 0) // if the ith iteration is divisible by 3 and 5, print "FizzBuzz"
        {
            printf("FizzBuzz\n");
        }
        else // if nothing gets printed (ie. no criteria met), increment counter
        {
            counter++;
        }
    }
    return counter; // return the counter
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
