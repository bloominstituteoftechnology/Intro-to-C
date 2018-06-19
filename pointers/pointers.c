#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int *a, int *b)
{
    // printf("value of a: %d, b: %d \n\n", a,b);
    // *a = b;
    // int aval = *a;
    // int aadd = &a;
    int c = *a;
    *a = *b;
    *b = c;
    // int bval = *b;
    // int badd = &b;
    // a = *b;
    // b = *a;
    // & a = bval;
    // & b = aval;
    // *b = a;
    // *a = b;
    // *b = a;
    // return a = *b, b = *a;
    // printf("value of a: %d, %d, b: %d  \n\n", &a, badd, aadd);
}

/*
    Given a character pointer s, returns the number of characters
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
    
    Do not just use the `strlen` function from the standard library.
*/
int string_length(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    printf("count of string %d", i);
    return i;
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
    while (*y)
    {
        *x = *y;
        x++;
        y++;
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
    
    Do not just use the `strcmp` function from the standard library.
*/
int string_compare(char *m, char *n)
{
    int i = 0;
    int mlength = string_length(&m) - 1;
    int nlength = string_length(&n) - 1;
    int max = 0;
    if (mlength > nlength) {
        max = mlength;
    } else if (mlength < nlength) {
        max = nlength;
    } else {
        max = nlength;
    };

    // while (m[i] !)
    // return m - n;

   for (;i <= max; i++) {
       if (m[i] != n[i]) {
        return *m - *n;
       } else if (m[i] == n[i]) {
           return 0;
       } else {
           printf("next");
       }
   }
    printf("character of m %c and n %c", m[i], n[i]);
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
