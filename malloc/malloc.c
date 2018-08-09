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
    int length = string_length(src);
    // you have to malloc +1 to account for the '\n'
    char *dup = malloc(length + 1);
    while ((*dup++ = *src++))
        ;
    *dup = '\0';
    return dup - length - 1;
}

/*
*mem_copy is a type agnostic function that copies src to dest with size n,
Work flow is just like a regular string copy, BUT because void types are not able to be dereferenced,
you have to type cast the void type to another type.
char is the least finicky of the types and is the best kind to be type cast to.
*/
void *mem_copy(void *dest, const void *src, int n)
{
    //create a new dereferenceable pointer which is the char type cast of the void *src
    char *csrc = (char *)src;
    //create a new dereferenceable pointer which is the char type cast of the void *dest
    char *cdest = (char *)dest;
    for (int i = 0; i < n; i++)
    {
        *(cdest + i) = *(csrc + i);
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
