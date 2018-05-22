#include <stdio.h>

int main(void)
{
  printf("Hello World\n");

  int age = 23;
  float weight = 132.65;

  char b = 'c';

  // char b[] = {'H', 'e', 'l', 'l', 'o'}; // an array of chars.
  int a[] = {1, 2, 3, 4, 6}; // an array of integers.
  a[2];                      // 3
  int y[10];                 // an integer array with space for 10 integers.

  // Arrays in C
  // 1. A contiguous block of memory in RAM
  // 2. A pointer to the first element in the array.

  //[ 1, 2, 3, 4, 6 ];
  //[ 'G', 'o', 'o', 'd', 'b', 'y', 'e', '\0' ];

  // declaring a pointer
  char *c = "Goodbye"; // this is how to make a String, an array of chars
  printf("Address of c pointer: %p\n", c);
  // dereferencing the pointer.
  printf("Value stroed at c pointer: %c\n", *c);

  // Pointer arithmetic
  for (int i = 0; i < 7; i++)
  {
    printf("%c\n", *(c + i)); //remove the derefernce *() to print the machine addresses.
  }

  // printf("%s\n", c);

  //JS
  const string = [ 'G', 'o', 'o', 'd', 'b', 'y', 'e', '\0' ];
  let index = 0; //pointer to first element G
  let index = 0x7ffee7fef518;
  let firstItem = string[index];
  let secondItem = string[index + 1];

  char *string = "Goodbye";
  // printf("%p/n", string); //the address that ram stores
  printf("%p/n", string);   // prints 0x7ffee7fef518
  char firstItem = *string; //* gives you the value the pointers pointing too (G)
  //w/o * gives just the address
  char secondItem = *(string + 1); // moves it one spot over to o then gives value of it which is o

  //finding the length of an array
  int integers[] = {9, 49, 1, 6, 10, 15};
  int length = sizeof(integers) / sizeof(int); // => 6
  // c knows the size of int
  char aString[] = {'H',
                    'e',
                    'l',
                    'l',
                    'o',
                    ' ',
                    'W',
                    'o',
                    'r',
                    'l',
                    'd',
                    '\0'};

  int aLength = sizeof(aString) / sizeof(char); //=> 12

  // pointers take up more room * is a pointer
  // finding the length this way doesn't work because the size of char is different than int
  char *bString = "Hello World";
  int bLength = sizeof(bString) / sizeof(char);

  printf("aLength: %d\n", aLength);
  printf("bLength: %d\n", bLength);

  return 0;
  // 0 means that the program ran successfully
}

//*variable is the value stored at the memory location
//variable is the memory address
