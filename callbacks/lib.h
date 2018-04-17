#ifndef lib_h
#define lib_h

#include <string.h>

void swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void *mem_copy(void *x, const void *y, int n)
{
  return memcpy(x, y, n);
}

#endif