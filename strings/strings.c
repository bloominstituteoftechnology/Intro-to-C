#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
  int count = 0;
  for (int i = 0; s[i] != '\0'; i++) {
      count++;
  }
  return count;
}
// solution lecture
// int string_length(char s[]){
//     int i = 0;
//     char cur = s[i];
//     while(cur != '\0'){
//         i++;
//         cur = s[i];
//     }
//     return i;
// }

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
// char *reverse_string(char rv[], char s[])
// {
//   int count = 0;
//   for (int j = string_length(s) - 1; j >= 0; j--) 
//   {
//     rv[count] = s[j];
//     count++;
//   }
//   rv[count] = '\0';
//   return rv;
// }

// solution lecture
char *reverse_string(char rv[], char s[]){
    for (int i = 0; i < string_length(s); i++){
        rv[i] = s[string_length(s) - i - 1];
    }
    rv[string_length(s)] = '\0';
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
    
