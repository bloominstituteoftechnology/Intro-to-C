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
    // SUDOCODE
    // int count = 0
    // if n / 3 
    //   if n / 5
    //   printf("%c\n", "fizzbuzz");
    //     return 0;
    //    printf("%c\n", "fizz")
    //    return 0
    // if n/ 5
    //   printf("%c\n", "buzz")
    //   return 0
    // count + 1
    // return count
int *p = &n;
printf("%d\n", *p );
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
