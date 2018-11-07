#ifndef lib_h
#define lib_h

#include <string.h>

char *string_dup(char *src)
{
  int len = strlen(src);
  char *chars = malloc(len);
  for(int i = 0; i< len; i++) {
    chars[i] = src[i];
  }
  chars[len] = '\0';
  return chars;
}

#endif