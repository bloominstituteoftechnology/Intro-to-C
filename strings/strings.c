#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
  int counter = 0;
  while (s[counter] != '\0')
  {
    counter += 1;
  }
  return counter;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/

// gcc -o strings strings.c
// ./strings
// add -g -Wall for debugging
char *reverse_string(char rv[], char s[])
{
  int s_length = string_length(s);
  int counter = 0;
  for (int i = s_length - 1; i >= 0; i--)
  {
    // printf("%d %d\n", counter, i);
    printf("s[i] %c\n", s[i]);
    rv[counter] = s[i];
    printf("Rv char %c\n", rv[counter]);
    counter++;
  }
  rv[counter] = '\0'; //terminates the string
  return rv;
}
// int length = string_length(s) - 1;
// int counter = 0;
// while (counter < string_length(s))
// {
//   rv[counter] = s[length];
//   counter++;
//   length--;
// }
// rv[counter] = '\0';
// return rv;
// }

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
