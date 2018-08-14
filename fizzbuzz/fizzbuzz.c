#include <stdio.h>

/*
    Your fizzbuzz implementation should initialize a counter, then
    iterate n times. If the ith iteration is divisible by 3, print
    "Fizz". If it's divisible by 5, print "Buzz". If it's divisible
    by both 3 and 5, print "FizzBuzz". Increment the counter variable
    every time that nothing gets printed and return the counter.
    Don't forget to include newlines '\n' in your printf statements!
*/
int fizzbuzz(int n) {
//looping through 1 to 100 incrementing by 1
for (int i=1; i <=100; i++) {
    if (n > 0) {
        //if n is divided by 3 and leaves no remainder
        // and n is divided by 5 with no remainder
        // print fizzbuzz digits newline
        if((n % 3 == 0) && (n % 5 == 0)) {
            printf("Fizzbuzz %d\n", i);
            //if you loop through and find numbers divided by 5 with no remainder
            //print buzz
        }else if(n % 5 == 0) {
            printf("Buzz %d\n", i);
        } else if (n % 3 == 0) {
            printF("Fizz %d\n", i);
        }
    return 0;
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
