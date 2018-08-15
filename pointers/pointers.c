#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int *a, int *b)
{
    int temp = *a; // set the variable temp to be the value of the pointer a
    *a = *b;       // set the value that a points at to be the value of the pointer b
    *b = temp;     // set the value that b points at to be the value of temp
}

/*
    Given a character pointer s, returns the number of characters
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
    
    Do not just use the `strlen` function from the standard library.
*/
int string_length(char *s)
{
    //initialize a counter variable
    int counter = 0;
    // while loop where at the beginning of the loop, *s points to the first character in the string. On the next iteration, it gets incremented and then prints out the second character in the string. This keeps going until the pointer points to the null character, which terminates the loop.
    while (*s != '\0')
    {
        counter++; // increment counter
        s++;       //increment where the pointer is at
    }
    return counter; // returns the number of characters
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
    // *y points to the first character in the string and will continue until it hits the null character
    while (*y != '\0')
    {
        // set the value that x points at to be the value of the pointer y
        *x = *y;
        y++; // increment the position along the string y
        x++; // increment the position along the string x
    }
    *x = '\0'; //x points to a null character at its end to terminate properly
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
    while (*m == *n) // loop continues while both characters match
    {
        if (*m == '\0') // if you reach the end of the string and both strings match, return 0
        {
            return 0;
        }
        m++; // increment the position along the string m
        n++; // increment the position along the string n
    }
    return *m - *n; // as soon as the strings no longer match break out of the loop and return the ascii difference between the value of m and n
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
