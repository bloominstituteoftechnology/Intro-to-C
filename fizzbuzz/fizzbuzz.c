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
//looping thru 1 to 100 incrementing by 1
for(int i=1; i <=100; ++i){
    if (i > 0){
        //if i is didvided by 3 and leaves no remainder
        //and i is divided by 5 with no remainer
        //print FizzBuzz digits newline
    if((i % 3 == 0) && (i % 5 == 0)){
        printf("FizzBuzz %d\n", i);
        //if you go thru loop and find numbers divivded by 5 with no remainder
        //print Buzz
    }else if(i % 5 == 0){
        printf("Buzz %d\n", i);     }
    }else if (i % 3 == 0){
        printf("Fizz %d\n", i);
        
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
