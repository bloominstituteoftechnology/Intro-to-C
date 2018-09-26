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
    int value = 0;
    int count = n;
    while (count > 0) {
        if (count % 3 == 0 && count % 5 == 0) {
            printf("FizzBuzz");
        } else if (count % 3 == 0) {
            printf("Fizz");
        } else if (count % 5 == 0) {
            printf("Buzz");
        } else {
            value += 1;
        }
        count -= 1;
        printf("%d", count);
    }
    return value;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
