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
    int c = 1;
    int returnCounter = 0;
    while (c <= n) {
        if (c % 15 == 0) {
            printf("fizzbuzz\n");
        }
        else if (c % 5 == 0) {
            printf("buzz\n");
        }
        else if (c % 3 == 0) {
            printf("fizz\n");
        }
        else {
            returnCounter ++;
        }
        c++;
    }
    return returnCounter;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
