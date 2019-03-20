#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
*/
char *string_dup(char *src)
{
    // get length of src
    int length = strlen(src);
    // printf("%d", string_length);
    // assign duplicate to malloc with length
    char *copy = malloc(length);
    //while deref src does not equal null char
    while (*src != '\0')
    {
        // assign deref duplicate to deref src
        *copy = *src;
        // increment duplicate
        copy++;
        // increment src
        src++;
    };
    // duplicate now in correct position should have null char
    *copy = '\0';
    // return the the copy pointer which is at the end minus the length
    return copy - length;
}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).
    You may want to cast the input pointers to char pointers first before
    performing the copying. `n` is the amount of data that should be copied
    from `src` to `dest`. 
*/
void mem_copy(void *dest, const void *src, int n)
{
    // dest is pointer malloc(n * sizeof(int))
    // src is pointer value of first index of arr
    // n is n * sizeof(int), returns amount of mem allocated to that data type
    // assign new char type copy pointer with void type pointer dest typecasted to char
    char *copy = (char *)dest;
    // assign new char type source pointer with void type pointer src typecasted to char
    char *source = (char *)src;
    // copy by looping until int variable reaches size of n , which is int type length of numbers array
    for (int i = 0; i < n; i++)
    {
        // value at index i from source pointer, is copied to copy pointer
        copy[i] = source[i];
    }
    // no return, return is void
}

/*
    Given a pointer of `malloc`'d memory, this function will 
    attempt to resize the allocated memory to the new specified
    size. Any data that was previously in the old `malloc`'d 
    memory should be intact in the new resized block of memory. 
    Some edge cases to consider: how should resizing be handled
    in the case when old_size < new_size? What about when 
    old_size > new_size?
    
    Do not use the `realloc` function from the standard libary.
*/
void *resize_memory(void *ptr, int old_size, int new_size)
{
    // void type ptr points to h in char array / some arbitrary pointer, have to type cast
    // int old_size is length of url
    // int new_size is length of url length -1 and path

    // assign new char type pointer with void type point ptr typecasted to char
    char *pointer = (char *)ptr;
    // in the case old_size is smaller than new_size
    if (old_size < new_size)
    {
        // invoke mem_copy, pass in pointer, as new destination pointer, ptr as source pointer,
        // old_size as length of numbers in array
        mem_copy(pointer, ptr, old_size);
    }
    // in case old_size is greater than new_size
    else if (old_size > new_size)
    {
        // invoke mem_copy, pass in pointer, as new destination pointer, ptr as source pointer,
        // new_size as length of numbers in array
        mem_copy(pointer, ptr, new_size);
    }
    // return pointer
    return pointer;
}

#ifndef TESTING
int main(void)
{
    char *s = "Some string to duplicate.";
    char *dup = string_dup(s);

    printf("Duplicated string: %s\n", dup);

    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    // memory required for numbers array divided by memory required for first index of array
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int *target = malloc(n * sizeof(int));

    mem_copy(target, numbers, n * sizeof(int));

    printf("Copied array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", target[i]);
    }

    printf("\n");

    char *url = string_dup("http://lambdaschool.com");
    char *path = string_dup("/students/");
    int url_length = string_length(url);
    int path_length = string_length(path);

    int new_length = url_length - 1 + path_length;
    char *new_url = resize_memory(url, url_length, new_length);
    char *p = new_url + url_length;

    while (*path != '\0')
    {
        *p = *path;
        p++;
        path++;
    }

    printf("Full path string: %s\n", new_url);

    return 0;
}
#endif