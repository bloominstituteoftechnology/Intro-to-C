#ifndef lib_h
#define lib_h

#include <string.h>

void swap(int* a, int* b)
{
  printf("a before: %i \n", *a);
  int temp = *a;
  *a = *b;
  *b = temp;
  printf("a after: %i \n", *a);
}

void *mem_copy(void *x, const void *y, int n)
{
  return memcpy(x, y, n);
}

#endif