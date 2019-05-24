#ifndef lib_h
#define lib_h

#include <string.h>

char *strdup(const char *);

char *string_dup(char *src)
{
  return strdup(src);
}

#endif