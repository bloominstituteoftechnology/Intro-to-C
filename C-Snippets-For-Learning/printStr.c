#include <stdio.h>
void main() 
{
  char *str = "This is a string";
  while (*str != '\0') {
      printf("%c", *str);
      str++;
  }
}
