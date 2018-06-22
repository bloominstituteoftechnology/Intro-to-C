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
    char *str = src;
    int lsrc = string_length(src);
    str = malloc(lsrc + 1);
    printf("Lenght of lsrc %d\n", lsrc);
    char *p = src;
    printf("This is the str string %s\n", str);
    int count = 0;
    while (count != 2)
    {
        int track = 0;
        int i;
        int end = lsrc;
        for (i = track; end > i; i++)
        {
            str[i] = src[i];
        }
        count++;
        if (i == end)
        {
            for (i = track; lsrc > i; i++)
            {
                str[i + end] = src[i];
            }
        }
        if (i == end)
        {
            int ending = end * 2 + 1;
            str[ending] = '\0';
        }
        count++;
    }
    printf("This is the duplicate string %s\n", str);

    return str;
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

    // int dup[];
    // dup = malloc(n);

    char *dup = (char *) src;
    char *ddest = (char *) dest;
    for (int i = 0; i < n; i++)
    {
        ddest[i] = dup[i];
    }
    //  printf("This is the array %d\n", src);
    printf("This is the size %d\n", sizeof(src));
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
