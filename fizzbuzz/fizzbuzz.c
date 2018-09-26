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
    // char fizz = "Fizz";
    // char buzz = "Buzz";
    // char fizz_buzz = "FizzBuzz";
    int count = 0;
    for ( int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("FizzBuzz, %d\n",i);
            // printf("%s\n", fizz_buzz);
            // count++;
        }
        else if (i % 3 == 0) {
            printf("Fizz, %d\n",i);
            // printf("%s\n", fizz);
            // count++;
        }
        else if (i % 5 == 0) {
            printf("Buzz, %d\n",i);
            // printf("%s\n", buzz);
            // count++;
        }
        else count++;
    }
    return count;
}
    // while (count <= n) {
    //     if (count == 0) {
    //         count++;
    //     }
    //     if (count % 3 == 0 && count % 5 == 0) {
    //         printf("FizzBuzz, %d\n",count);
    //         // printf("%s\n", fizz_buzz);
    //         count++;
    //     }
    //     else if (count % 3 == 0) {
    //         printf("Fizz, %d\n",count);
    //         // printf("%s\n", fizz);
    //         count++;
    //     }
    //     else if (count % 5 == 0) {
    //         printf("Buzz, %d\n",count);
    //         // printf("%s\n", buzz);
    //         count++;
    //     }
    //     else {
    //         count++;
    //     }
    // }
// return printf("%d\n",count);
// return count;
// }

// int main(void){
//     fizzbuzz(3);
//     // fizzbuzz(2);
//     fizzbuzz(10);
//     // fizzbuzz(15);
//     return 0;
// }
#ifndef TESTING
int main(void)
{
    fizzbuzz(20); 
    return 0;
}
#endif

