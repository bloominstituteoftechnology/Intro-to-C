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

int src_length(char src[]) // or *src
{

    int count = 0;
    while (*src != '\0')
    {
        count++;
        src++;
    }
    //printf(" string_length %d \n", count);
    return count;
}
///////////////////////////////////////

char string_dup(char *src)
{
    int length = src_length(src); //25
    // printf("%d \n", length);
    char *dup_src = malloc(length); /// allocating empty pointer with  enough bytes in memory 1 char = 1 byte , 1 int = 4 bytes
    int i;
    for (i = 0; i <= length; i++)
    {
        dup_src[i] = src[i]; // assinging the string items to the pointer
    }
    printf("%s \n", dup_src);    // printing the pointer value : the string (all array)
    printf("%p \n", dup_src);    // printing the pointer address
    for (int i = 0; i < 25; i++) // printing the array (string ) elements
    {
        printf("%c ", dup_src[i]);
    }
    printf("\n");
    return *dup_src;
}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).

	n is the number of bytes to copy.

    You may want to cast the input pointers to char pointers first before
    performing the copying. 
    
    Do not just use the `memcpy` function from the standard library.
*/

void mem_copy(void *target, const void *numbers, int n) // fn accept void parameters
{

    char *new_target = (char *)target; // definting type of parameter to  character by casting

    char *new_numbers = (char *)numbers; // definting type of parameter to  character by casting

    int i;
    for (i = 0; i <= n; i++)
    {
        new_target[i] = new_numbers[i];
    }
    printf("%p \n", new_target);
    printf("Copied array: ");
    for (int i = 0; i < n; i += 4) // printing the array (integers) elements and jumping by 4 bytes
    {
        printf("%d ", new_target[i]);
    }
    printf("\n");
}

#ifndef TESTING
int main(void)
{
    char *s = "Some string to duplicate.";
    string_dup(s);

    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    // printf(" number of items in the array %d \n", n);
    int *target = malloc(n * sizeof(int)); /// *target is new array in the heap (memory) created by malloc

    mem_copy(target, numbers, n * sizeof(int));

    // printf("Copied array: ");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", target[i]);
    // }
    // printf("\n");

    return 0;
}
#endif
