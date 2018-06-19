#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
    
    Do not just use the `strdup` function from the standard library.
*/
char *string_dup(char *src)
{
    int strLength = string_length(src);
    char *dup_Chars = malloc(strLength + 1); // +1 to compensate for null terminator
    char *saved = dup_Chars;                 // return this pointer, which will point to the array strings copied

    while (*src != '\0')
    {
        *dup_Chars++ = *src++;
    }
    *dup_Chars = 0;

    return saved; // you CANNOT directly return array; instead you need to return a pointer to the array.
}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).

	n is the number of bytes to copy.

    You may want to cast the input pointers to char pointers first before
    performing the copying. 
    
    Do not just use the `memcpy` function from the standard library.
*/
void *mem_copy(void *dest, const void *src, int n)
{
    char *c_src = (char *)src; // cast; changing type from void to char
    char *c_dest = (char *)dest;

    // alternative way
    // const char *c_src = src;
    // char *c_dest = dest;

    for (int i = 0; i < n; i++)
    {
        *(c_dest + i) = *(c_src + i);
    }
}

#ifndef TESTING
int main(void)
{
    char *s = "Some string to duplicate.";
    char *dup = string_dup(s);

    printf("Duplicated string: %s\n", dup);

    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int *target = malloc(n * sizeof(int));

    mem_copy(target, numbers, n * sizeof(int));

    printf("Copied array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", target[i]);
    }

    printf("\n");

    return 0;
}
#endif
