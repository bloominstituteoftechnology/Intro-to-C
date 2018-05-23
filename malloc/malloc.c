#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
*/
// char *string_dup(char *src)
// {
//     // length of src needed to determine size of `copy`
//     int length = string_length(src);
//     // `copy` created using malloc function
//     char *copy = malloc(length);

//     // iterates through indices setting copy[i] = to the value of src[i]
//     for (int i = 0; i < length; i++) {
//         copy[i] = src[i]; 
//     }
//     // sets the final character to '\0'
//     copy[length] = '\0';
//     // returns finished `copy`
//     return copy;
// }

// Sean's Solution:

char *string_dup(char *src)
{
    int len = string_length(src);

    char *str = malloc(len + 1); // #QUESTION: Why plus 1???, is it for the NULL '\0'?...Passes without it :/

    for(int i = 0; i < len; i++) {
        *(str + i) = *(src + i);
    }
    *(str + len) = '\0';
    return str;
}


/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).

	n is the number of bytes to copy.

    You may want to cast the input pointers to char pointers first before
    performing the copying. 
*/
// Here the void indicates that this function returns a void(void) pointer(*)
// void *mem_copy(void *dest, const void *src, int n)
// {

//     // Example Given:
//     // int *100_ints = malloc(100 * sizeof(int));
//     // char *50_chars = malloc(51);
  
//     // cast the input pointers to char pointers
//     // you need to do this because you cannot assign a value to a void
//     // pointer (void *dest).  "void pointer" meaning it is pointing to
//     // a void `data type`. 
//     char *result = (char *)dest; // #QUESTION: What is going on here?
//     char *source = (char *)src;
//     // printf("RESULT: %d\n", result);

//     for (int i = 0; i < n; i++ ) {
//         // printf("i is %i AND ", i);
//         // printf("source[i] is %d\n", source[i]);
//         result[i] = source[i];
//     }
//     result[n] = '\0';

// }

// Sean's Solution:
// Keeping a void type mem_copy, we now get around the restrictions of a type
// system.  You can pass in numbers or strings as the src pointer and it will
// work either way.
void *mem_copy(void *dest, const void *src, int n){
    // Changing the *dest data type from `void` to `char`
    // Here you are changing not the value of the item, but the type of the pointer.
    // BOTH `void *dest` AND `char *dest` point to the same memory address and value.
    // Of course we change the VALUE from `void` to those values found in src
    char *csrc = (char *) src; // Take the type in this src variable, and change it to the type specified => char *
    char *cdest = (char *) dest;

    for (int i = 0; i < n; i++) {
        *cdest++ = *csrc++;
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
