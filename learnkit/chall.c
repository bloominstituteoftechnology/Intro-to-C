#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int x = 1, y = 2, z[10];
  printf("Initial value of x: %d\n", x);
  printf("Initial value of y: %d\n", y);

  int *ip;
  
  printf("Initial value of ip: %p\n", ip);
  
  ip = &x;  // What is ip here?
  printf("\nSet ip to &x...\n");
  printf("Address of x: %p\n", ip); //SHould be another address location of x

  y = *ip; // What is y here?
  printf("\nSet y to *ip ...\n");
  printf("Value of y: %p\n", y); //The value of y should now be the value of x, 1 (pointers default to display in hex)
  printf("Value of y: %d\n", y); //The value of y should now be the value of x, 1 (changing to d show value as 1)

  *ip = 0; // What is ip here now? What is x now?
  printf("\nSet *ip = 0...\n");
  printf("Address of ip: %p\n", ip); //Should be the 0th address location?
  printf("Value of x: %d\n", x); //x should be the same, however, y ...
  printf("Value of y: %d\n", y); //y should now be different?


  ip = &z[0];    // What is ip now?
  printf("Address of ip: %p\n", ip); //Should be the 0th address location?
  printf("Value of x: %d\n", x); //x should be the same, however, y ...
  printf("Value of y: %d\n", y); //y should now be different?
  printf("Value of z: %d\n", z); //y should now be different?
  return 0;
}