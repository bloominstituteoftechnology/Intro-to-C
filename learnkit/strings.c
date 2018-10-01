#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  // char *str = "Hello, world!";
  // printf("%p\n", str);
  // printf("%s\n", *str);
  
  // Or into an array:
  // char t[] = "This is the secret message";
  // char *u = t; // t and u both refer to the same string

  char *str = "I'm a string!";
  printf("%p\n", str); // the address
  printf("%c\n", *str); // the first char
  printf("%s\n", str); // Entire string, start's at pointer and goes until it reaches '\0' or 00 (address)

  return 0;

}