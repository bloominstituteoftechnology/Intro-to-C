#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int integers[] = { 9, 49, 1, 6, 10, 15 };
  printf("Length of integers: %d\n", sizeof(integers)/sizeof(int));

  int *ptr_2_int = integers; //This points to the first value of the array ()

  int vala = *ptr_2_int;
  int valb = *(ptr_2_int+1);
  printf("Pointer 2 int: %p\n", ptr_2_int);


  char *str = "Some string";
  while (*str != '\0') {
      printf("%c", *str);
      str++; // This is actually changing the str array in the heap. Run in Python Tutor to see.
  }
  printf("\n");

}