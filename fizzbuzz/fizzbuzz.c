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
    int counter = 0; // initialize counter at index 0

    for (int i = 0; i < n; i++ ) {  // for loop to iterate over the elements in n
        if (i % 3 == 0 && i % 5 == 0) { // if index/item is divisible by 3 & 5, print 'FizzBuzz'
            printf("FizzBuzz");
        } 
        else if (i % 3 == 0) {  // else if index/item is divisible by 3, print 'Fizz'
            printf("Fizz");
        } 
        else if  (i % 5 == 0) { // else if index/item is divisible by 5, print 'Buzz'
            printf("Buzz");
        } else {
            counter++;  // else if item is neither divisible by 3 or 5, increment counter
        }
        printf("\n");   // new line
    }
    return counter;     // return counter
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
