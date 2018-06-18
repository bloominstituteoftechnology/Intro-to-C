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
    // set up a count varaible
    int count =0;
    //increment over the while i is less than n
    for (int i = 1; i <n; i++)
    {
        // check i mod 3 and mod 5
    if((i%3==0)&&(i%5==0))
    {
        //console log fizzbuzz 
     printf("Fizzbuzz\n");
    }

    //check if i is modulo 3
    else if(i % 3 == 0)
    {
        printf("Fizz\n");
    }
    // check i modulo 5
      else if(i % 5 == 0)
    {
        printf("Buzz\n");
    } 
    else
    //increment count
    count++;   
}
// console log the count
printf("%d:\n",count);
// return the count
return count;
}
#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
