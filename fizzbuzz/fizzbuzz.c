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

    int count = 0;           //initialize counter
    int i;                   // inits. i in the for loop as an int, can also initialize in the loop itself
    for (i = 1; i <= n; i++) // for loop iterates from 0 - n
    {
        if (i % 3 == 0 && i % 5 != 0) //if divisible by three but not divisible by five, so order isn't as much an issue
        {
            printf("Fizz\n"); //prints fizz
        }
        else if (i % 3 == 0 && i % 5 == 0) // if i divided by 3 and 5 is divisible without a remainder then -
        {
            printf("FizzBuzz\n"); // - prints FizzBuzz
        }
        else if (i % 5 == 0) // otherwise if only divisible by 5
        {
            printf("Buzz\n"); // prints Buzz
        }
        else
        {
            count++; // counts up one
        }
    }
    return count;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
