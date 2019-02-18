#include <stdio.h>

void add2(int *i)
{
  *i += 2;
}

int main(void)
{
  int x =12;
  printf("x is: %d\n", x);
  add2(&x);
  printf("x is: %d\n", x)
  return 0;
}