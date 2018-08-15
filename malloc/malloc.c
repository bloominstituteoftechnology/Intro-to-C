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

    // integer src_lenght is equal to the return from string_length on src

    // char pointer copy equals the pointer for an area in memory

    // large enough to accomodate the string src

    int src_length = string_length(src);

    char *copy = malloc(src_length);



    // starting with i = 0 and before i is greater than the length of the string,

    // the value of copy at index i is equal to the value of src at index i

    for (int i = 0; i <= src_length; i++)

    {

        copy[i] = src[i];

    }

    return copy;

}



/*

    A generic version of string_copy, mem_copy receives a block of memory

    of any type and copies its contents to the destination pointer (dest).

    `n` is the number of bytes to copy. You may want to cast the input 

    pointers to char pointers first before performing the copying. 

    

    Do not just use the `memcpy` function from the standard library.

*/

void *mem_copy(void *dest, const void *src, int n)

{

    // char pointer char_dest is equal to the pointer dest after being

    // cast as a char pointer

    // char pointer char_src is equal to pointer src after being

    // cast as a char pointer

    char *char_dest = (char*)dest;

    char *char_src = (char*)src;

    // starting with i = 0 and until i is less than the number of bytes 

    // to copy, set the value of char_dest at index i to be equal to

    // the value of char_src at index i.

    for (int i = 0; i < n; i++)

    {

        char_dest[i] = char_src[i];

    }

    return char_dest;

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