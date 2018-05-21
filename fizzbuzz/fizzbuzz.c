#include <stdio.h>

/*
    Your fizzbuzz implementation should initialize a counter, then
    iterate n times. If the ith iteration is divisible by 3, print
    "Fizz". If it's divisible by 5, print "Buzz". If it's divisible
    by both 3 and 5, print "FizzBuzz". Increment the counter variable
    every time that nothing gets printed and return the counter.
*/
int fizzbuzz(int n)
{
  if (n % 5 == 0 && n % 3 == 0)
  {
    printf("fizzbuzz\n");
  }
  else if (n % 5 == 0)
  {
    printf("buzz\n");
  }
  else if (n % 3 == 0)
  {
    printf("fizz\n");
  }

  return 0;
}

#ifndef TESTING
int main(void)
{
  fizzbuzz(225);

  return 0;
}
#endif