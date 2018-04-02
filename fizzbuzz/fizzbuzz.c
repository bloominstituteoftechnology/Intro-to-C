#include <stdio.h>

/*
    Your fizzbuzz implementation should initialize a counter, then
    iterate n times. If the ith iteration is divisible by 3, print
    "Fizz". If it's divisible by 5, print "Buzz". If it's divisible
    by both 3 and 5, print "FizzBuzz". Increment the counter variable
    every time that nothing gets printed and return the counter.
*/
int fizzbuzz(int n)
{for (n = 0; n <= 100; n++)
    if (n % 3 == 0) {
         printf("Fizz %d", n);
    }

    else if (n % 5 == 0) {
         printf("Buzz %d", n);
    }

    else if (n % 3 == 0 && n % 5 == 0) {
         printf("FizzBuzz %d", n);
    }

    else {
        printf("%d", n);
    }

return 0;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif