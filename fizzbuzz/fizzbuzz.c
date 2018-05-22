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
{ //intializing a counter
    int counter = 0;
    //iterating n times
    for (int i = 1; i <= n; i++)
    { //if divisible by 3
        if (i % 3 == 0)
        {
            //print fizz
            printf("Fizz\n");
        }
        //if divisible by 5
        else if (i % 5 == 0)
        {
            //print buzz
            printf("Buzz\n");
        }
        //if divisible by both 3 and 5
        else if (i % 3 == 0 && i % 5 == 0)
        {
            //print fizzbuzz
            printf("FizzBuzz\n");
        }
        else
        {
            //incrementing counter everytime that nothing gets printed
            counter++;
        }
    }
    //returning counter
    return counter;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
