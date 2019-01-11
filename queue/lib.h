#ifndef lib_h
#define lib_h

#include <stdlib.h>

void *resize_memory(void *ptr, int new_size) // Delete `int old_size` because kept getting errors
{
  return realloc(ptr, new_size);
}

#endif