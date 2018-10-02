#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    // go as long as *str != 0
    while (*str)
    {
        if (*str == c)
        {
            return str;
        }
        str++;
    }
    return NULL;
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
    int i = 0;
    while (*y)
    {
        // x at i equals the dereferened y char
        x[i] = *y;
        // next i
        i++;
        // next pointer place for y
        y++;
    }
    // always remember to add the null at the end
    x[i] = '\0';
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
    // as long as char m == char n and neither is 0
    while (*m == *n && *m && *n)
    {
        // advance both pointers
        m++;
        n++;
    }
    // if we've iterated to the end of both, then
    // *m and *n are both 0, so will return 0
    // otherwise we're at the first place that's difference
    // and `-` will return the correct value
    return *m - *n;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    // go as long as char != 0
    while (*haystack)
    {
        // grab pointer for first letter
        char *start = haystack;

        // If first character of sub-string match, check for whole string
        while (*haystack && *needle && *haystack == *needle)
        {
            haystack++;
            needle++;
        }
        // have we reached the end of needle?
        if (!*needle)
            // if we get here, we've a match
            // so return the start pointer
            return start;

        // no match yet, go to next letter
        haystack = start + 1;
    }
    return NULL;
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
    printf("Comparison is %d\n", string_compare(hello, world));

    char *found_char = find_char(hello, 'e');
    // char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
