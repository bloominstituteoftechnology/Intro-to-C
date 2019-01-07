#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
  int len = 0; // initiate a counter to track letters of a strings

  for (int i = 0; s[i] != '\0'; i++) // loop until hits null character (terminating condition)
  {
    len++; // increments length counter for every letter in string
  }

  // printf("length of string: %i \n", length); // prints length of the string
  return len;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
  int pos = 0;                  // set starting position of rv string
  int s_len = string_length(s); // length of the string

  for (int i = s_len - 1; i >= 0; i--) // length of the string minus 1 because of zero-index
  {
    rv[pos] = s[i]; // for each position in reversed string (rv), set the letter from the string (s)
    pos++;          // move to the next position in the reversed string
  }

  rv[pos] = '\0'; // set the last position to null character to terminate the string

  // printf("Reversed string: %s --> %s \n", s, rv); // prints the old string --> reversed string
  return rv;
}

#ifndef TESTING
int main(void)
{
  char quote1[] = "Don't forget to be awesome";
  char quote2[] = "a man a plan a canal panama";

  char rv[512];

  printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
  printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

  return 0;
}
#endif
