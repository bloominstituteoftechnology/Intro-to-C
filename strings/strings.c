#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters
    held inside it.

    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
  // set an int to 0
  int length = 0;

  // loop until we get the the end of the char array and add 1 to length
  while (s[length] != '\0') {
    length++;
  }

  return length;
}

/*
    Write a function that reverses the order of string s and outputs
    the reversed string to the input array rv. The rv array will have
    enough space for the reversed string. Don't forget to terminate
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
  // Get the length of the current string
  int length = string_length(s);

  // Initialize the rv's index
  int j = 0;

  // loop backwards appending the element at s[i] to rv
  for (int i = length - 1; i >= 0; i--) {
    // Set the index of rv to the index of s
    rv[j] = s[i];
    // Increase the index
    j++;
  }

  // Add the ending of the string
  rv[j] = '\0';
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
