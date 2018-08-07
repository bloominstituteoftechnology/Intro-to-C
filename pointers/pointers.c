#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
    Given a character pointer s, returns the number of characters
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
    
    Do not just use the `strlen` function from the standard library.
*/
size_t string_length(char* s)
{
    size_t len = 0;
    while(*(s+len) != '\0') {
        len++;
    }
    return len;
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
    
    Do not just use the `strcpy` function from the standard library.
*/
void string_copy(char* x, char* y)
{
    size_t len_y = string_length(y);
    for(size_t i = 0; i < len_y; i++)
    {
        *(x+i) = *(y+i);
    }
    *(x+len_y) = '\0';
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
int string_compare(char* m, char* n)
{
    int diff = 0;
    size_t lhs_len = string_length(m);
    size_t rhs_len = string_length(n);
    size_t len = lhs_len == rhs_len ? lhs_len : MIN(lhs_len, rhs_len) + 1;
    for (size_t i = 0; i < len + 1; i++) {
        if (diff != 0) { break; }
        diff += *(m+i) - *(n+i);
    }
    return diff;
}

#ifndef TESTING
int main(void)
{
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);

    char* hello = "Hello";
    char* world = "World";

    char buffer[1024];
    string_copy(buffer, hello);

    printf("Buffer is %s\n", buffer);
    printf("Length is %d\n", string_length(buffer));
    printf("Comparison is %d\n", string_compare(hello, world));

    return EXIT_SUCCESS;
}
#endif
