#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
  char compare = 'a';
  int counter = 0;
  for (int i = 0; compare != 0; i++) {
    compare = s[i];
    counter += 1;
  }
  return counter - 1;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
  char compare = 'a';
  int counter = 0;
  for (int i = 0; compare != 0; i++) {
    compare = s[i];
    counter += 1;
  }

  int i = 0;
  for (int j = counter - 1; j >= 0; j -= 1) {
    rv[i] = s[j];
    i += 1;
    //printf("%c\n", s[j]);
    printf("%c\n", rv[i]);
  }
  printf("%s\n", rv);
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
    
