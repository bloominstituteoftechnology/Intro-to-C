#include <stdio.h>

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Pointer arithmetic
    is necessary here. Also, make sure x points to a null terminator at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
        while (*y != '\0') 
    {
        //copy x to y
        *x = *y;
        // inc x and y
        x++;
        y++;
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
    //while there is a string
    while (*str != '\0')
  {
      //if string = c
    if (*str == c)
    {
        //return
      return str;
    }
    //inc
    str++;
  }
  return NULL;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    char *start = find_char(haystack, needle[0]);
    for (int i = 0; needle[i] != '\0'; i++)
  {
    if (start[i] != needle[i])
    {
      return NULL;
    }
  }
  return start;

}

#ifndef TESTING
int main(void)
{   
    char *hello = "hello";
    char *world = "world";
    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
