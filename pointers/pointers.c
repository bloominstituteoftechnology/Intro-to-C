#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int *a, int *b)
{
    int temp = *a; // defining an intermediate variable, temp, which is initialized to one of the two variables, for example a
    *a = *b;       // assigning the value of the second variable,b to the first (saved in temp) variable a (now temp has value a and a has value b)
    *b = temp;     // finally, assigning temp, to the second variable, b (now a has the value of b and vice versa)
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
    while (*s != '\0')
    {
        s++; // increase the address until the tombstone break point
        i++; // i follows s allowing it to pick up everything s passes over and stops with s at tombstone
    }
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
    while (*y != '\0')
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
    while (*m == *n) // matching chars in both pointers
    {
        if (*m == '\0') // add break point using tombstone/zero-case
        {
            return 0; // if m reaches this point, they are matching strings, thus 0
        }
        m++; //
        n++;
    }

    return *m - *n;
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
