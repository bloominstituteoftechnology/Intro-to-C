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
    int n = string_length(src); // get string length for src
    char *str = malloc(n + 1);  // create pointer *str  using malloc n + 1

    for (int i = 0; i < n; i++) {   // for loop to iterate over the elements in i
        *(str+i) = *(src+i);  // using pointer arithmetic syntax, str + i then de-reference by setting it to src + i
        // str[i] = src[i];
    }
    *(str+n) = '\0';    // null terminator

    return str;     // return str
}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).
    `n` is the number of bytes to copy. You may want to cast the input 
    pointers to char pointers first before performing the copying. 
    
    Do not just use the `memcpy` function from the standard library.
*/
void mem_copy(void *dest, const void *src, int n)   // void pointers need to be cast into an apppropriate type
{
    char *csrc = src;       // casting src into *csrc using char which is single byte 
    char *cdest = dest;     // casting dest into *cdest using char which is single byte

    for (int i = 0; i < n; i++) {   // for loop to iterate over the elements in i
        *(cdest+i) = *(csrc+i);     
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

    for (int i = 0; i < n; i++) {
        printf("%d ", target[i]);
    }

    printf("\n");

    return 0;
}
#endif
