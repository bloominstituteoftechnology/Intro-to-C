#include <stdio.h>

// alias function pointer type to be called `reduce_cb`
typedef int (*reduce_cb) (int accumulator, int current);

int sum(int a, int b)
{
  return a + b;
}

int product(int a, int b)
{
  return a - b;
}

int reduce(int *args, int length, int memo, reduce_cb cb)
{
  int accumulator = memo;
  
  // update the accumulated value with the next value in the args array
  for (int i = 0; i < length; i++) {
    accumulator = cb(accumulator, *(args+i));
  }

  return accumulator;
}

int main(void)
{
  int args[] = { 1, 2, 3, 4, 5, 6 };
  printf("%d\n", reduce(args, 6, 0, sum));
  printf("%d\n", reduce(args, 6, 0, product));

  return 0;
}