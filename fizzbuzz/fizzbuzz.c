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
    int c = 0;

    for ( int i = 0; i <= n; i++) {
        // check if divis by 3 & 5 => print fizz buzz
        if( i % 3 == 0 && i % 5 == 0) {
            printf("%d is divisible by 3 and 5 -- FizzBuzz!\n", i);
        // check if divis by 3 => print fizz
        } else if (i % 3 == 0) {
            printf("%d is divisible by 3 and not 5 -- Fizz!\n", i);
        // check if divis by 5 => print buzz
        } else if (i % 5 == 0) {
            printf("%d is divisible by 5 but not 3 -- Buzz!\n", i);
        } else {
            printf("%d is not divisible by 5 nor 3 -- WOMP!\n", i);
            c++;
        }
    }
    return c;

}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
