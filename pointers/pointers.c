#include <stdio.h>
#include <string.h>
#include "pointers.h"

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Pointer arithmetic
    is necessary here. Also, make sure x points to a null terminator at its 
    end to terminate it properly. 
*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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
    int count = strlen(str);
    
    for (int index = 0; index < count; index++) {
        char character = str[index];    // Get the value
        
        if (character == c) {
            return &str[index];    // return a pointer
        }
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
//    *x = *y;
////    *x = 
    
    for (int index = 0; ; index++) {
        x[index] = y[index];    // Get y value at index, and assign it to x at same index
        
        if (y[index] == 0) {
            break;
        }
    }
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
    for (int index = 0; ; index++) {
        char charM = m[index];
        char charN = n[index];
        
        char difference = charM - charN;
        
        if (difference != 0) {
            return difference;
        } else if (charM == 0) {
            return 0;
        }
    }
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
    // strlen() needs to loop through the entire string to get the length, so if we can skip it, it'll be faster
//    int count = strlen(haystack);
//    int needleCount = strlen(needle);
    int needleIndex = 0;
    
    for (int index = 0; /* index < count */; index++) {
        char character = haystack[index];    // Get the value
        
        if (character == needle[needleIndex] && character != 0) { // Check the current letter of the needle
            needleIndex++;
        } else if (needle[needleIndex] == 0) { // if they didn't match, but the needle is at it's final index, return the original pointer
            return &haystack[index - needleIndex];    // return a pointer
        } else { // if they didn't match because the letters were different, restart the process at the current letter
            needleIndex = 0;
            
            if (character == needle[needleIndex]) { // make sure to check the current letter against the needle's first letter, just incase it matches
                needleIndex++;
            }
        }
        
        if (character == 0) { // if we went though the entire haystack and didn't find anything, retutn a NULL pointer because we don't have a condition that would stop the loop for us
            return NULL;
        }
    }
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
