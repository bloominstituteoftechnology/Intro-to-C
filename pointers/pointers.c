#include <stdio.h>
#include <string.h>
/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Pointer arithmetic
    is necessary here. Also, make sure x points to a null terminator at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
  int ylength = strlen(y);
  int counter = 0;

  while (ylength)
  {
    x[counter] = y[counter];
    ylength--;
    counter++;
  }
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
  char *match = NULL;
  int str_length = strlen(str);

  for (int x = 0; x < str_length; x++)
  {
    if (str[x] == c)
    {
      match = &str[x];
    }
  }
  return match;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
/*
    find length of haystack and needle
    iterate through haystack until you find the first character of needle in haystack
    if found, start iteration of needle and haystack until
    all characters from needle come back true
    if pattern breaks, return NULL
    -----
    create 3 variables: 2 ints = 0, char pointer.

*/

char *find_string(char *haystack, char *needle)
{
  int needle_length = strlen(needle);
  char *match = haystack;
  int x = 0;
  int y = 0;

  for (x = 0; haystack[x] != '\0'; x++)
  {
    if (haystack[x] == needle[y])
    {
      match = &haystack[x];
      int x_container = 0;
      for (y = 0; needle[y] != '\0'; y++)
      {
        if (needle[y] == '\0')
        {
          return match;
        }

        if (needle[y] == haystack[x])
        {
          x++;
          x_container++;
        }
      }

      if (needle[y] == '\0' && x_container == needle_length)
      {
        return match;
      }
    }
  }
  return NULL;
}

#ifndef TESTING
int main(void)
{
  char *found_char = find_char("hello", 'e');
  char *found_string = find_string("world", "or");

  printf("Found char: %s\n", found_char);
  printf("Found string: %s\n", found_string);

  return 0;
}
#endif
