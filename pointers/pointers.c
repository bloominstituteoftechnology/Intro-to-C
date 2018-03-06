#include <stdio.h>
#include <string.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int* a, int* b)
{

    // printf("The original value of A: %d and its address is:%p\n", *a,&a);
    // printf("The original value of B: %d and its address is:%p\n", *b,&b);
    int swpr = *a;
    *a = *b;
    *b = swpr;

    // printf("Value A: %d and its address is: %p\n", *a, &a);
    // printf("Value B: %d and its address is: %p\n", *b, &b);

}

/*
    Given a character pointer s, returns the number of characters
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
*/
int string_length(char *s)
{
   int length = 0;
   while(*s != '\0') {
       length++;
       s++;
   }
   return length;
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    while (*y != '\0') {
        *x = *y;
        x++;
        y++;
    }
    *x = '\0';
    printf("x is: %s\n y is: %s\n", x, y);
}

/* 
    Compares the character strings m and n and returns negative,
    0, or positive if n is lexicographically less than, equal to,
    or greater than n. To calculate lexicographic difference, find
    the difference between the first characters in m and n that differ.
    
    For example, given matching strings, this function should 
    return 0. Given strings m = "hello world" and n = "goodbye",
    this function should return a negative value. Given strings
    m = "aardvark" and n = "zebra", should return a positive
    value.
*/
int string_compare(char *m, char *n)
{
    int acc = *m -*n;
      while(*m != '\0' && *n != '\0' && acc == 0) {
          acc = *m - *n;
          n++;
          m++;
      }
      return acc;
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