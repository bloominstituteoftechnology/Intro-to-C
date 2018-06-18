#include <stdio.h>
#include <math.h>
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
    int p = 0;
    int q = 0;
    while (p != n)
    {
        if ((p % 3) == 0 && (p % 5) == 0 && p != 0)
        {
            printf("FizzBuzz \n");
        }
        else if ((p % 3) == 0 && p != 0)
        {
            printf("Fizz \n");
        }
        else if ((p % 5) == 0 && p != 0)
        {
            printf("Buzz \n");
        } else {
            q++;
        };
        p++;
        // return ++p;

    };
    return q;
};

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
