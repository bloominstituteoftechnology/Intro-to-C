#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int *a, int *b)
{
    // *a += *b;
    // *b = *a - *b;
    // *a -= *b;

    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
    
    Do not just use the `strlen` function from the standard library.
*/
int string_length(char *s)
{
    int size = 0;

    while (*s != '\0')
    {
        printf("%c\n", *s); // print a char in the string
        size++;
        s++; // increment pointer
    }
    printf("SIZE: %d\n", size);
    return size;
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
    
    Do not just use the `strcpy` function from the standard library.
*/
void string_copy(char *x, char *y)
{
    // int add = 0;

    // while (*(y + add) != '0\n')
    // {
    //     *(x + add) = *(y + add);
    //     add++;
    //     // printf("char: %s\n", x);
    // }
    // x[add] = '\0';
    // printf("STRING: %s\n", y);

    // alternative solution
    // find length of y
    int ysize = string_length(y);
    int idx = 0;
    printf("ysize: %d\n", ysize);
    // loop over y and add chars to x
    while (idx < ysize) {
      x[idx] = y[idx];
      printf("x value: %c\n", x[idx]);
      idx++;
    }
    printf("idx: %d\n", idx);
    printf("x at idx: %d\n", x[idx]);
    printf("copied: %s\n", x);
}

/* 
    Compares the character strings m and n and returns negative,
    0, or positive if n is lexicographically less than, equal to,
    or greater than n. To calculate lexicographic difference, find
    the difference between the first characters in m and n that differ.
    
    For example, given matching strings, this function should 
    return 0. Given strings m = "hello world" and n = "goodbye",
    this function should return a positive value. Given strings
    m = "aardvark" and n = "zebra", should return a negative
    value.
    
    Do not just use the `strcmp` function from the standard library.
*/
int string_compare(char *m, char *n)
{
  printf("string m: %s\n", m);
  printf("string n: %s\n", n);

  // length is the largest string length
  int length = 0;
  // m is larger than n
  if (string_length(m) > string_length(n)) {
    length = string_length(m);
  } 
  // n is larger than m
  else if (string_length(m) < string_length(n)) {
    length = string_length(n);
  }
  // m and n are the same size
  else {
    length = string_length(m);
  }
  // loop to length, the largest string size possible
  for (int i = 0; i < length; i++) {
    if (m[i] != n[i]) {
      // find the lexicographic difference where m and n do not match
      printf("m[i] - n[i]: %d\n", (m[i] - n[i]));
      return (m[i] - n[i]);
    }
  }
  // default case: all chars are matching
  return 0;
}

#ifndef TESTING
int main(void)
{
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);

    char *hello = "Hello";
    char *world = "World";

    char buffer[1024];
    string_copy(buffer, hello);

    printf("Buffer is %s\n", buffer);
    printf("Length is %d\n", string_length(buffer));
    printf("Comparison is %d\n", string_compare(hello, world));

    return 0;
}
#endif
