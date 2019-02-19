#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  // static declaration
  int ints[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

  // malloc doesn't know the type. Under the hood it is void * malloc
  // In the example below malloc is told the type is int *
  // int *ints = malloc(9 * sizeof(int)) // 9 bytes * size of 1 int
  char *s = "Hello World";

  // get the length of ints
  int l = sizeof(ints) / sizeof(int);

  int l_2 = strlen(s);

  for (int i = 0; i < l; i++) {
    printf("%d", ints[i]);  // equiavlent to printf("%d", *(ints + i)); 
  }
  return 0;
}
/*

Asterisk is the inverse of Ampersand

Turn pointer into a value with *
Turn value into a pointer with &

int *p; // variable p is pointer to integer type
int i; // integer value

Storage Location    52        68        74
Values              10        52        68
Variables            x         y         z

int x = 10;   // Reference to the Value
int *y = &x;  // location in memory int *y = x same as int y = &x is the value
int *z = &y;  // location in memory

int x = 10
int *y = &x       Sets pointer y to x's place in memory not its value.
printf("%p", &x)  Both print the same place in memory
printf("%p", y)   Both print the same place in memory

*/

/*
memcpy is a generic copy that takes all types.
memcpy(src, dst, n) (copy from source to destination of n number of bytes)
void *memcpy(void *str1, const void *str2, size_t n)


*/