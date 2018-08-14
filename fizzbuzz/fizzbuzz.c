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
    // init a counter
    int counter = 0;

    // loop over the input
    for (int i=0; i<n; i++)
    {   
        // if divisible by 3, but not 5, print Fizz
        if (i % 3 == 0 && i %5 !=0)
        {
            printf("Fizz \n");
        }
        // if divisible by 5, but not 3, print Buzz
        else if (i % 5 == 0 && i%3 !=0)
        {
            printf("Buzz \n");
        }
        // if divisible by both 3 and 5, print fizzbuzz
        else if (i % 3 == 0 && i % 5 == 0)
        {
            printf("FizzBuzz \n");
        }
        // if none of the above, increment the counter
        else 
        {
            counter++;
        }
    }
    // return the counter
    return counter;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
