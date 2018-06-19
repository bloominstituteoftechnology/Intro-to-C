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

    int count = 2;
    int divisible = 3;
    if (n < divisible)
    {
        printf(" %d is smaller then 3 \n ", n);
    }
    else
    {

        while (count < n)
        {
            count++;
            int solution = count % divisible;
            if (solution > 0)
            {
                printf("buzz \n");
            }
            else
            {
                printf(" fizz \n");
            }
        }
    }
    return 0;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
