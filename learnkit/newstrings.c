#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int string_length(char s[])
{ 
  int len = 0;

  //Using Pointer Arithmetic
  // for (int i=0; *(s+i) != 0; i++ )
  // {
  //   // printf("Print first char as char: %c\n", *(s+i));
  //   len++;
  // }

  //Using Arrays
  for (int i=0; s[i] != 0; i++ )
  {
    // printf("Print first char as char: %c\n", *(s+i));
    len++;
  }
  
  // printf("Print first char as char: %c\n", *(s+1));
  // printf("Print first char as char: %c\n", *(s+1));
  // printf("Print entire string: %s",s);
  return len;
}

char *reverse_string(char rv[], char s[])
{
    for (int i=string_length(s)-1; i >= 0; i--){
        rv[string_length(s)-i-1] = s[i];
        // printf("reverse order: %c",s[i]);
    }
    rv[string_length(s)] = '\0';

    // printf("Print rv[0] %c\n", rv[0]);
    // printf("Print rv[1] %c\n", rv[1]);
    // printf("Print rv[2] %c\n", rv[2]);
    // printf("Print rv[3] %c\n", rv[3]);
    // printf("Print rv[4] %c\n", rv[4]);
    // printf("Print rv[5] %c\n", rv[5]);
    
    // printf("Print rv %s\n", rv);

    // return (char *) rv;
    return rv;
}

int main(void)
{
  // char *str = "Hello, world!";
  // printf("%p\n", str);
  // printf("%s\n", *str);
  
  // Or into an array:
  char t[] = "This is the secret message";
  // char *u = t; // t and u both refer to the same string

  // char *str = "I'm a string!";
  // printf("%p\n", str); // the address
  // printf("%c\n", *str); // the first char
  // printf("%s\n", str); // Entire string, start's at pointer and goes until it reaches '\0' or 00 (address)

  // printf("%s\n", t);
  // printf("Length of t:%d\n", strlen(t));
  // printf("Length via function: %d\n", string_length(t));

  char rv[50];
  // printf("reverse String func: %p",reverse_string(rv, t));
  // reverse_string(t);
  printf("Reverse String Function call: %s\n", reverse_string(rv, t));
  // reverse_string(rv, t);

  return 0;
}





// void reverse_string(char s[])
// {
//     for (int i=string_length(s); i >= 0; i--){
//         // rv[string_length(s)-i] = s[i];
//         printf("reverse order: %c\n", s[i]);
//     }
// }