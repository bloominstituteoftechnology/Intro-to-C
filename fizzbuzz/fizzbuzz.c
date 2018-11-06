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
int count = 0;
for (int i = 0; i < n; i++) {
    
    if (i % 3 ==  0) { // if (i % 3 == 0 && i % 5 == 0) { works too
        if (i % 5 == 0 ) {
            printf("FizzBuzz\n");
            // count--;
        }
        printf("Fizz\n");
        // count--;
    }
    else if (i % 5 == 0 ) {
        printf("Buzz\n");
        // count--; // why count--? before I had the count switched to the else it would keep the count from actually going up.
                   //but also when I try the tests it gets closer with some combination of the count thing
         // that is a weird error, but also we wouldn't need continue, right?
        // because all the logic is in if/if else/else, there's no danger of code you don't want to be running running 
        // My count was set to 1 because how I was handling it before. I don't know how I made this problem that crazy. 
        // R: Don't worry about it XD We lived, learned, and now get to go to the next problem which is strings rite m8? yes m8 alright well meet you there
    }
    else {
        count++;
    } // this probably should be in an else. The counter should only be incremented if neither Fizz AND/OR Buzz is printed
    // But as it is now, the count is going to increment in every iteration, right?
}
printf("%d\n", count); // ZzzzzZzzzzzZZZzzz 1 sec over here
return count;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
