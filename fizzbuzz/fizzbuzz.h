#include <stdio.h>
#ifndef fizzbuzz_h
#define fizzbuzz_h
int fizzbuzz(int n)
{
  int counter = 0;
  for (int i = 1; i < n; i++)
  {
    if ((i % 3 == 0) && (i % 5 == 0))
    {
      printf("%d: fizzbuzz\n", i);
    }
    else if (i % 3 == 0)
    {
      printf("%d: fizz\n", i);
    }
    else if (i % 5 == 0)
    {
      printf("%d: buzz\n", i);
    }
    else
    {
      counter++;
    }
  }
  return counter;
}
#endif