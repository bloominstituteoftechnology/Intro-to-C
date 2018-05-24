#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int *a, int *b)
{
    // *a -> 2233ffcc -> 4 | *b -> 45ffcf -> 9
    int temp = *a; // temp == 4
    *a = *b;        // a == 9
    *b = temp;     // b == 4
    // printf(" a is equal to %d\n", a);
    // printf("b is equal to %d", b);
}

/*
    Given a character pointer s, returns the number of characters
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
*/
int string_length(char *s)
{
    int length = 0;
    while (*s != '\0') {
        s++;
        length++;
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
    y++;
    x++;
  }
  *x = '\0';
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
    h8 - g7 = 1
    a1 - z26 = -25
*/
int string_compare(char *m, char *n)
{
    char letters[] = "abcdefghijklmnopqrstuvwxyz";

    
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
