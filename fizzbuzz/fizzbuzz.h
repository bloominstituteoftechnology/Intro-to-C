#include <stdio.h>
#ifndef fizzbuzz_h
#define fizzbuzz_h

/*
* fizzbuzz
* @param { int: n } Number of times to loop the fizzbuzz condition check.
* @return { int: counter } Number of times that it was unsuccessful matching.
*/
int fizzbuzz(int n)
{
  int counter = 0;
  for (int i = 1; i < n; i++)
  {
    if ((i % 3 == 0) && (i % 5 == 0))
    {
      printf("%d: FizzBuzz\n", i);
    }
    else if (i % 3 == 0)
    {
      printf("%d: Fizz\n", i);
    }
    else if (i % 5 == 0)
    {
      printf("%d: Buzz\n", i);
    }
    else
    {
      counter++;
    }
  }
  return counter;
}
#endif