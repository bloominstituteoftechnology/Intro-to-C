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
    int counter = 0; // initalize counter
    for(int i = 0; i < n; i++){ //create a loop
        if (i % 3 == 0 && i % 5 == 0) // test the fizzbuzz case first, as this case case has the trickest logic
        {
            printf("%s FizzBuzz");
        }
        else if (i % 3 == 0) // test fizz logic
        {
            printf("%s Fizz");
        }
        else if (i % 5 == 0) // test buzz logic
        {
            printf("%s Buzz");
        }
        else
        {
            counter++; // if all else fails, increase the counter by 1
        }
    }
    
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
