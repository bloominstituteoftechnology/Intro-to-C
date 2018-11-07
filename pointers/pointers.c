#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the
    address it's referring to) or the value at the address it's
    pointing at.
*/
void swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
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
  char *result = 0;
  int i = 0;
  while(str[i] != '\0') {
    if(str[i] == c) {
      result = &str[i];
      break;
    }
    i++;
  }
  return result;
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its
    end to terminate it properly.

    Do not just use the `strcpy` function from the standard library.
*/
void string_copy(char *x, char *y)
{
  int i = 0;
  while (y[i] != '\0') {
    x[i] = y[i];
    i++;
  }
  x[i] = '\0';

}

/*
    Compares the character strings m and n and returns negative,
    0, or positive if n is lexicographically less than, equal to,
    or greater than n. To calculate lexicographic difference, find
    the difference between the first characters in m and n that differ.

    For example, given matching strings, this function should
    return 0. Given strings m = "hello world" and n = "goodbye",
    this function should return a positive value. Given strings
    m = "aardvark" and n = "zebra", should return a negative
    value.

    Do not just use the `strcmp` function from the standard library.
*/
int string_compare(char *m, char *n)
{
  int result = 0;
  int i = 0;
  while (m[i] != '\0') {
    if (m[i] != n[i]) {
      result = m[i] - n[i];
      break;
    }
    i++;
  }
  if (m[i] != n[i]) {
    result = m[i] - n[i];
  }
  return result;
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
  char *result = 0;
  int hay_i = 0;
  while (haystack[hay_i] != '\0') {
    if(haystack[hay_i] == needle[0]) {
      result = &haystack[hay_i];
      for (int x = 1; needle[x] != '\0'; x++) {
        if (haystack[hay_i+x] != needle[x]) {
          result = 0;
        }
      }
      if(result != 0){
        break;
      }
    }
    hay_i++;
  }
  return result;
}

#ifndef TESTING
int main(void)
{
    // int x = 10, y = 20;
    // swap(&x, &y);
    // printf("x=%d, y=%d\n", x, y);

    char *hello = "Hello";
    char *world = "World";
    char buffer[1024];

    string_copy(buffer, hello);

    char *firetruck = "firetruck";
    char *firetrucks = "firetrucks";

    printf("Buffer is %s\n", buffer);
    printf("Comparison is %d\n", string_compare(firetruck, firetrucks));
    char *str = "LambdaSchool";
    char *found_char = find_char(str, 's');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
