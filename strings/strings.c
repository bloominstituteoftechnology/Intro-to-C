#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
  char * q;
  int length = 0;
  
  for (q = s; *q !='\0'; q++) {
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
  int start, end, counter = 0;
  while (s[counter] != '\0')
    counter++;
  end = counter - 1;
  for (start = 0; start < counter; start++) {
    rv[start] = s[end];
    end--;
  }
  rv[start] = '\0';
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
    
