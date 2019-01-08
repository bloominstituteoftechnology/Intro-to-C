#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int *a, int *b)
{
  int value_a = *a; // grabs original value of a
  int value_b = *b; // grabs original value of b
  *a = value_b;     // sets value at pointer a to value of b
  *b = value_a;     // sets value at pointer b to value of a

  // printf("Swapped a and b: %i %i --> %i %i  \n", value_a, value_b, *a, *b); // prints out values
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
  while (*str != '\0') // while not at the end of a string
  {
    if (*str == c) // if value at position in string equals the character c
    {
      return str; // return the pointer, or address to character in the string
    }
    str++; // if there's no match at the current string position, move to the next position
  }

  return 0;
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
  while (*y != '\0') // while not the end of character contents of y
  {
    *x = *y; // set x value as y
    x++;     // increments position in x
    y++;     // increments position in y
  }
  *x = '\0'; // terminate new string
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
  while (*m != '\0' || (*n != '\0')) // while not the end of m or n
  {
    if ((*m - *n) > 0) // if difference is positive
      return 1;
    else if ((*m - *n) < 0) // if difference is negative
      return -1;
    m++; // increments to next letter in string of m
    n++; // increments to next letter in string of n
  }

  return 0; // when both strings reach the end and there was no difference between the strings
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
  // FOUR
  // 1 2 3 4 5 6 7
  // ^
  // h e l l o \0
  // ^
  // e \0

  // 1 2 3 4 5 6 7 8
  // ^
  // w o r l d l y \0
  // ^
  // o r \0
  // ^
  // l d \0

  while (*haystack != '\0') // While there's a value for haystack and not "\0" aka 0 or false
  {
    char *pHaystack = haystack; // Set up a pointer to the pointer to haystack string, because we need return a pointer at the end

    while (*haystack != '\0' &&
           *needle != '\0' &&
           *haystack == *needle) // While both values exist and are equal to each other
    {
      haystack++; // Increment the address of haystack by 1 byte (char = 1 byte) in memory, subsequently the next letter
      needle++;   // Increment the address of needle by 1 byte (char = 1 byte) in memory, subsequently the next letter
    }

    if (*needle == '\0') // If the value of needle reaches the end
    {
      return pHaystack; // Return the pointer to *haystack, pHaystack incremented only if 
    }

    haystack++; // Increments haystack if the letters don't match, pHaystack also updates
  }

  return NULL; // If nothing is found

  // THREE
  // while (*haystack != '\0') // While there's a value for haystack and not "\0" aka 0 or false
  // {
  //   char *pHaystack = haystack; // Set up a pointer to the pointer to haystack string
  //   char *pNeedle = needle; // Set up a pointer to the pointer to needle substring

  //   while(*haystack != '\0' && *pNeedle != '\0' && *haystack == *pNeedle) // While there's a value in haystack string and an pointer at pNeedle
  //   {
  //     haystack++; // Increment the address of haystack by 1 byte (char = 1 byte) in memory, subsequently the next letter
  //     pNeedle++; // Increment the address of pNeedle by 1 byte (char = 1 byte) in memory, subsequently the next letter
  //   }

  //   if (*pNeedle == '\0') // If the value of pNeedle reaches the end
  //   {
  //     return pHaystack; // Return the pointer to *haystack, basically true
  //   }

  //   haystack = pHaystack + 1; // Increments haystack main string
  // }

  // return NULL; // If nothing is found

  // TWO
  // while (*haystack != '\0')
  // {
  //   if ((*haystack == *needle) && !string_compare(haystack, needle))
  //   {
  //     return haystack;
  //   }
  //   haystack++;
  // }
  // return NULL;

  // ONE
  // while (*haystack != '\0')
  // {
  //   char word_check;
  //   int word_counter = 0;

  //   if (*haystack == *needle)
  //   {
  //     word_check[word_counter] = *needle;
  //     word_counter++;
  //     haystack++;
  //     needle++;
  //   }
  //   else if (*haystack != *needle)
  //   {
  //     haystack++;
  //   }

  //   if (*needle != '\0')
  //     return 0;
  // }
  // return NULL;
}

#ifndef TESTING
int main(void)
{
  int x = 10, y = 20;
  swap(&x, &y);
  printf("x=%d, y=%d\n", x, y);

  char *hello = "Hello";
  char *world = "World";
  char *worldly = "Worldly";
  char buffer[1024];

  string_copy(buffer, hello);

  printf("Buffer is %s\n", buffer);
  printf("Comparison is %d\n", string_compare(hello, world));

  char *found_char = find_char(hello, 'e');
  char *found_string = find_string(world, "or");
  char *found_string2 = find_string(worldly, "ld");

  printf("Found char: %s\n", found_char);
  printf("Found string: %s\n", found_string);
  printf("Found string2: %s\n", found_string2);

  return 0;
}
#endif
