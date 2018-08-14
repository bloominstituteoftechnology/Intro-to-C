#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int* a, int* b)
{
    // a and b are pointers
    // store a's value on a temporary variable
    int temp = *a;
    // turn a's value for b's
    *a = *b;
    // reassign b's value to the temporary variable, effectively swapping them
    *b = temp;
}

/*
    Given a character pointer s, returns the number of characters
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
    
    Do not just use the `strlen` function from the standard library.
*/
int string_length(char *s)
{
    // init a counter
    int n = 0;
    // while the counter isn't the end of the string,
    // increment the counter for each char
    while (*s != '\0')
    {
        n++;
        s++;
    }
    // return the counter
    return n;
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
    // dereference y, check its value, and as long as it is not the null terminator,
    // we continue to increment it until it hits the null terminator
    while (*y != '\0')
    {
        *x = *y; //copy value
        y++; // incrememnt y
        x++; // increment x
    }
    *x = '\0'; // x(which is actually y), is dereferenced, and has advanced to the last chracter
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
    // while characters match, continue to the next block of code
    while (*m == *n)
    {
        // if the while loop reaches the null terminator, return 0 for a match
        if (*m == '\0')
        {
            return 0;
        }
        m++; // iterate on m
        n++; // iterate on n
    }
    // if no match, subtract their values, and it will return a negative value to 
    // symbolize "no match"
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
