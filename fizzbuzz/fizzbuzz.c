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
  int q, r;

  for (int i = 0; i < n; i++) {
    int q = i%3;
    int r = i%5;
    if(q == 0 && r == 0) {
      printf("FizzBuzz\n");
    }
    else if(q == 0) {
      printf("Fizz\n");
    }
    else if (r == 0) {
      printf("Buzz\n");
    }
    else {
      counter++;
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
