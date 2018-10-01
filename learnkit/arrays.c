#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int a[20]; // array of 20 ints

  printf("%p\n", a);     // Sucess! - Gives the memory location of a
  // printf('%p\n', *a); // Warning - makes pointer from integer without a cast
  // printf('%p\n', &a); // Warning - makes pointer from integer without a cast

  // float f[2][20]; // 2D array, 2 rows of 20 columns of floats
  int b[5] = {4, 7, 2, 9, 3};
  printf("%p\n", b);     // Sucess! - Gives the memory location of b (different from a)
  // printf('%p\n', *b); // Warning - makes pointer from integer without a cast
  // printf('%d\n', &b); // Warning - makes pointer from integer without a cast



  // int c[2][3] = { { 1,2,3}, {4,5,6} };

  // // Autosize the array to 3 elements:
  // int d[] = {10, 50, 100};

  return 0;
};