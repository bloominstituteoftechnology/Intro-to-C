/*
Author Jonathan Jamel Holloway
Purpose to practice using conditonal statements in C programming language 
Date 11-5-18
*/
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
    for (int x = 1; x <= n; x++)
    {
        if (x % 3 == 0 && x % 5 == 0)
        {
            printf("FizzBuzz\n");
        }
        else if (x % 3 == 0)
        {
            printf("Fizz\n");
        }
        else if (x % 5 == 0)
        {
            printf("Buzz\n");
        }
        else
        {
            counter++;
        }
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
//https://repl.it/@codejoncode/fizzbuzz