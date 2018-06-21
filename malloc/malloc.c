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
    // set a string length variable calling the string_legth passing in the src
int strLength = string_length(src);
// set a char variable  and call malloc, passing the string length
char *rv = malloc(strLength);
// initialize a count setting it to 0
int count =0;
// while the counter is lower than the length of the string
while(count<=strLength)
{
    // set rv at the index of count to src at the index of count
 rv[count] = src[count];
 //increment the count
 count++;
}
//return the coppied rv variable
return rv;
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
    //set void pointer to char pointer
    char *destCopy = dest;
    //set cosnt char for the src pointer
    const char *srcCopy = src;
    // iterate while i<n
for(int i =0; i <n; i++)
{
    // set the copy of dest at i to the copy of src at i
    destCopy[i] = srcCopy[i];
}
// return my copy of dest
return destCopy;
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
