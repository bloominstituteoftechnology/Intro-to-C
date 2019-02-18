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
    for(n = 0; n < 5; n = n + 1){
        if (n / 3){
            printf("%s\n Fizz");
            count = count + 1;
        }else if(n / 5){
            printf("%s\n Buzz");
            count = count + 1;
        }else if((n / 5) && (n / 3)){
            count = count + 1;
            printf("%s\n FizzBuzz");
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
