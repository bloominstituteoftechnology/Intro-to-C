// The C preprocessor (conceptually is a seperate first step in compilation) provides certain
// file facilities such as #include, which includes the contents of a file in compilation
// (i.e. file inclusion).
            // This is equivalent to including all the code in studio.h and pasting in place 
            // of the line of code.
#include <stdio.h> //stdio is the standard input/output library

/*
    Your fizzbuzz implementation should initialize a counter, then
    iterate n times. If the ith iteration is divisible by 3, print
    "Fizz". If it's divisible by 5, print "Buzz". If it's divisible
    by both 3 and 5, print "FizzBuzz". Increment the counter variable
    every time that nothing gets printed and return the counter.
    Don't forget to include newlines '\n' in your printf statements!
*/

// TESTS DON'T PASS. NOT SURE WHAT I'M DOING WRONG HERE.
int fizzbuzz(int n)
{
    int i;
    for (i = 1; i <= n; ++i)
        if (i % 3 == 0 && i % 5 == 0)
            printf("%d FizzBuzz\n", i);
        else if (i % 3 == 0)
            printf("%d Fizz\n", i);
        else if (i % 5 == 0)
            printf("%d Buzz\n", i);
        // else return i;    
        else printf("%d <--count:\n", i);
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(34);

    return 0;
}
#endif
