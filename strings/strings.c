#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s (as a pointer), return the number of 
    characters in the string.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s)
{
  char current = s[0];
  int len_str = 0;
  while (s[len_str] != '\0') {
    len_str++;
  }
  return len_str;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char *rv, char *s)
{
  // printf("%s, pointer: %p\n", rv, &rv);
  int len_str = string_length(s) - 1;

  for (int i = len_str; i >= 0; i--) {
    // printf("i: %d, len_str - i: %d\n", i, len_str - i);
    rv[len_str - i] = s[i];
  }

  // printf("%d\n", len_str);

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
    
