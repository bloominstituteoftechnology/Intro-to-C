#ifndef lib_h
#define lib_h

#include <string.h>

int string_length(char *s)
{
  return strlen(s);
}

void string_copy(char *x, char *y)
{
    while (*y != '\0') {
        *x++ = *y++;
    }

    *x = '\0';
}

#endif