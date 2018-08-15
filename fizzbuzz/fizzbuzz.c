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
    int counter = 0; //this initializes a counter that starts at 0 and increases as we iterate
//looping through 1 to n incrementing by 1
    for (int i=0; i <= n; i++) {
        //if n is divided by 3 and leaves no remainder
        // and n is divided by 5 with no remainder
        // print fizzbuzz digits newline
        if((i % 3 == 0) && (n % 5 == 0)) {
            printf("Fizzbuzz %d\n", i); //print out fizzbuzz
            //if you loop through and find numbers divided by 5 with no remainder
            //print buzz
        }else if(n % 5 == 0) { // if the number is divisible by 5
            printf("Buzz %d\n", i); //we print Buzz
        } else if (n % 3 == 0) { //if the number is divisible by 3
            printF("Fizz %d\n", i); // we print Fizz
        }
        else 
        {
            counter ++; //this iterates the counter
        }
    }
    return counter; // returns the current value of the counter
}


#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
