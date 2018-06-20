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
    int count = 0; // an integer variable count is set to 0.
    for (int i = 0; i < n; i++) // loop through what is passed in. 
    {
        if (i % 3 == 0 && i % 5 == 0) // if index is divisible by 3 and 5 to 0, print fizzbuzz
        {
            printf("FizzBuzz\n");
        }
        else if (i % 3 == 0) // if it is only divisible by 3 to 0 and not 5, print fizz
        {
            printf("Fizz\n");
        }
        else if (i % 5 == 0) //only 5? print buzz
        {
            printf("Buzz\n");
        }
        else count++; //increment count
    }
    return count; // return the count 
};

#ifndef TESTING
int main(void)
{
    fizzbuzz(20); // call the function with 20 passed in.

    return 0;
}
#endif
