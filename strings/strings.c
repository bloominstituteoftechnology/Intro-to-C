#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
  int i = 0;
  char string = s[i];
  while (string != '\0') {
    i++;
    string = s[i];
  }
  return i;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
  // int length = string_length(s) - 1;
  //   for (int i = length; i >= 0; i--)
  //   {
  //       rv[length - i] = s[i];
  //       printf("HERE HERE %s\n", rv);
  //   };
  //   rv[length] = '\0';
  //   return rv;
  int len = strlen(s);
  int count = 0;
  for (int i = len -1; i >= 0; i--) {
    *(rv + count) = *(s + i);
    count++;
  }
  *(rv + count) = '\0';
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
    
