#include <stdio.h>
#include <string.h>

void swap(int* a, int* b)
// Swaps the integer values being pointed at by a and b.
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
    Searches the input string `str` for the first instance of the character `c` (an unsigned char). This function returns a pointer that points to the first instance of the character `c` in the input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
  for (; *str != '\0'; str++) {
    if (*str == c) {
      return str;
    }
  }
  return NULL;
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
  while (*y != '\0') {
    *x++ = *y++;
  }
  *x = '\0';
}

/*
  Lexicographically compare the first character of m and n.
  return 0 if equal.
  return 1 if m's first char is greater than n's.
  return -1 if n's first char is less than m's.
*/
int string_compare(char *m, char *n)
{
  while (*m != '\0' || *n != '\0') {
    // printf("%c %c\n", *m, *n);
    if (*m > *n) {
      return 1;
    } else if (*m < *n) {
      return -1;
    } else if (*m == *n) {
      m++;
      n++;
    }
  }
  return 0;
}

/*
    Searches the input string `haystack` for the first instance of the string `needle`. This function returns a pointer that points to the first instance of the string `needle` in the input
    string `haystack`.

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
  char *pointer1, *pointer2;

  for (; *haystack != '\0'; haystack++) {
    pointer1 = haystack;
    pointer2 = needle;
    if (*haystack == *needle) {
      while (*pointer2 != '\0') {
        // printf("%c\n", *pointer1);
        if (*pointer1 != *pointer2) {
          break;
        }
        pointer1++;
        pointer2++;
      }
      if (*pointer2 == '\0') {
        return haystack;
      }
    }
  }

  return NULL;
}

#ifndef TESTING
int main(void)
{
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);

    char *hello = "Hello";
    char *world = "World";
    char buffer[1024];

    string_copy(buffer, hello);

    printf("Buffer is %s\n", buffer);
    printf("Comparison is %d\n", string_compare(hello, world));
    char *s = "firetruck";
    char *t = "firetrucks";
    printf("Comparison is %d\n", string_compare(s, t));
    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "ld");

    if (found_char) {
      printf("Found char: %c\n", *found_char);
    }
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
