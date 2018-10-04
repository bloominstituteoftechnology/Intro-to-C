#ifndef lib_h
#define lib_h

#include <string.h>

int string_length(char *s)
{
  return strlen(s);
}

void string_copy(char *x, char *y)
{
    int index = 0;
    while(y[index] != '\0')
    {
        x[index] = y[index];
        index++;
    }
    x[index] = '\0';

}

#endif