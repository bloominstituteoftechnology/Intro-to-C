#ifndef lib_h
#define lib_h

#include <stdlib.h>

void *resize_memory(void *ptr, int new_size)
{
  return realloc(ptr, new_size);
}

#endif