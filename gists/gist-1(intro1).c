// https://gist.github.com/seanchen1991/2f14814a920b76df1db7aec4f6e30caa

#include <stdio.h>

int main(void)
{
  printf("Hello world!\n");

  int age = 23;
  float weight = 132.65;

  char b = 'c';

  // declaring an array of integers
  int x[] = { 1, 2, 3, 4, 6 };
  // declaring an integer array with space for 5 integers
  int y[10];
  
  // declaring a string using array syntax
  char z[] = { 'H', 'e', 'l', 'l', 'o' };

  // Arrays in C
  // 1. A contiguous block of memory in RAM
  // 2. A pointer to the first element in the array

  // [1, 2, 3, 4, 6]
  // ['G', 'o', 'o', 'd', 'b', 'y', 'e', '\0']

  // declaring a pointer
  char *c = "Goodbye";
  // print the actual memory address
  printf("Address of c pointer: %p\n", c);
  // dereferencing the pointer and printing the value
  printf("Value stored at c pointer: %c\n", *c);

  // Pointer arithmetic
  for (int i = 0; i < 7; i++) {
    printf("%p\n", *(c+i));
  }

  // printf("%s\n", c);

  // JS
  const string = ['G', 'o', 'o', 'd', 'b', 'y', 'e', '\0'];
//   let index = 0x7ffee7fef518;
//   let firstItem = string[index];
//   let secondItem = string[index + 1];
  
  // Analogous pointer behavior
  char *string = "Goodbye";
  printf("%p\n", string);  // prints 0x7ffee7fef518
  char firstItem = *string;
  char secondItem = *(string + 1);

  // finding the length of an array
  int integers[] = { 9, 49, 1, 6, 10, 15 };
  int length = sizeof(integers) / sizeof(int); // => 6

  char aString[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};
  int aLength = sizeof(aString) / sizeof(char);  // => 8

  // however this doesn't work with a pointer
  char *bString = "Hello World";
  int bLength = sizeof(bString) / sizeof(char);

  printf("aLength: %d\n", aLength); 
  
  printf("bLength pointer length: %d\n", bLength); // prints the length of the actual memory address
  printf("bLength value length: %d\n", strlen(bLength));  // prints the length of the string value

  return 0;
}