#ifndef malloc_h
#define malloc_h

#include <lib.h>

char *string_dup(char *src)
{
  int end = string_length(src);
  char *newString = malloc(end + 1);
  char *p = newString;
  while (*src)
  {
    *p++ = *src++;
  }
  return newString;
}

void *mem_copy(void *dest, void *src, int n)
{
  char *csrc = src;
  char *cdest = dest;

  for (int i = 0; i < n; i++)
  {
    cdest[i] = csrc[i];
  }
  return dest;
}

#endif