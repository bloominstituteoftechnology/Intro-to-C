#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int* a, int* b)
{
    int x;
    
    x = *a; // x is now equal to the same value that 'a' points to
    *a = *b; // the value that 'a' points to is now equal to the value that 'b' points to
    *b = x; // the value 'b' points to is now equal to x's value (i.e. same as value 'a' used to point to)

}

/*
    Given a character pointer s, returns the number of characters
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
    
    Do not just use the `strlen` function from the standard library.
*/
int string_length(char *s)
{
    int counter = 0;

    while(*s != '\0') {
        counter += 1;
        s += 1;
    }
    return counter;
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
 
    int index = 0;
    while(*y != '\0') {
        x[index] = *y;
        y++;
        index++;
    }
    x[index] = '\0';
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
   int length_m = string_length(m);
   int length_n = string_length(n);
   char x;

   if (length_m > length_n) {
       x = m;
   }
   else x = n;

while(*n != '\0') {
    if (*m != *n) {
        if(*m - *n > 0) {
            return 1;
        }
        else if (*m - *n <0) {
            return -1;
        }
        else {
            return 0;
        } 
    }
    else {
        m++;
        n++;
    }
}
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
