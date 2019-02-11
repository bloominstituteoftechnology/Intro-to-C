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
    int countNotPrinted = 0;
    int c;
    for (c = 0; c < n; c++) {
        int isFizz = c % 3 == 0;
        int isBuzz = c % 5 == 0;
        
        if (isFizz) {
            printf("Fizz");
        } else if (isBuzz) {
            printf("Buzz");
        } else if (isFizz && isBuzz) {
            printf("FizzBuzz");
        } else {
            countNotPrinted++;
        }
    }
    return countNotPrinted;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
