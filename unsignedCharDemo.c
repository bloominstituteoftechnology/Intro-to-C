#include <stdio.h>
int main(void)
{
  unsigned char x;
  int y = 1234567;
  x = 12;
  printf("Value of x: %d\n", x);
  printf("size of x: %ld\n", sizeof x);
  printf("Address of x: %p\n", *x) // unknown ?

  printf("Value of y: %d\n", y);
  printf("size of y: %ld\n", sizeof y);
  printf("Address of y: %p\n", *y) // unknown ?
}