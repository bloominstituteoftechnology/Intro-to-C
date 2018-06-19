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

int src_length(char src[])
{

    int count = 0;
    while (*src != '\0')
    {
        count++;
        src++;
    }
    // printf(" string_length %d \n", count);
    return count;
}
///////////////////////////////////////

char *string_dup(char *src)
{
    int length = src_length(src);
    // printf("%d \n", length);
    char *dup_src = malloc(length);
    dup_src = src;
    //printf("%s \n", dup_src);
    return dup_src;
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
}

#ifndef TESTING
int main(void)
{
    char *s = "Some string to duplicate.";
    char *dup = string_dup(s);

    //printf("Duplicated string: %s\n", dup);

    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    printf(" size of the array %d \n", sizeof(numbers));
    printf(" size of  single element in array  %d \n", sizeof(numbers[0]));
    printf(" number of items in the array %d \n", n);

    int *target = malloc(n * sizeof(int)); /// *target is new array in the heap (memory) created by malloc

    mem_copy(target, numbers, n * sizeof(int));

    // printf("Copied array: ");

    // for (int i = 0; i < n; i++)
    //{
    //     printf("%d ", target[i]);
    // }

    //printf("\n");

    return 0;
}
#endif
