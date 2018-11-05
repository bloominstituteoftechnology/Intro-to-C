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
    int counter = 0;    
    int whileCounter = 0;

    while(whileCounter < n) {
      whileCounter = whileCounter + 1; 


      if(whileCounter % 3 == 0 && whileCounter % 5 == 0) {
        printf("%s\n", "fizzbuzz");
      } else if(whileCounter % 5 == 0){
        printf("%s\n", "buzz");
      } else if(whileCounter % 3 == 0){
        printf("%s\n", "fizz");
      } else {
        counter = counter + 1;
        continue;
      }
    }

return counter; 
}


#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
