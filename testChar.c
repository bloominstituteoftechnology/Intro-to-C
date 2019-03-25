#include <stdlib.h>

int main(void) {

  char * aStr = "hello";

  printf("char: %c \n", aStr[0] );
  printf("char: %c \n", *(aStr+2) );
  printf("address: %p \n", (aStr+2) );

  printf("char: %c \n", *(aStr+3) );
  printf("address: %p \n", (aStr+3) );



  printf("\nstring: %s, address: %p \n", aStr, aStr);

  return 0;
}
