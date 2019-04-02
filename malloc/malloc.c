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
    // figure out length of src
    int length = strlen(src);
    // allocate appropriate amount of memory for *src
    char *duplicate = (char*)malloc(length + 1 * sizeof(*src));
    // copy over src to the newly created memory
    int i;
    for (i = 0; i < length; i++) {
        duplicate[i] = src[i];
    }
    duplicate[length] = '\0';
    return duplicate;
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
    // casting the src as a char pointer
    const char *srcs = src;
    // char *temp;
    char *dests = dest;
    // copy src to dest and n determine the size of it
    int i;
    for (i = 0; i < n; i++) {
        dests[i] = srcs[i];
    }
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
    // ptr is the url itself
    // old_size reference the length of ptr
    // new_size is the length of old_size plus new content

    // Assigning ptr to be a char
    char *ptrs = ptr;

    // making comparison of old_size and new_size to ensure new_size is larger
    if ( old_size > new_size ) {
        EXIT_FAILURE;
    }
    // declare the new malloc size of new_size 
    char *new_malloc = (char*)malloc(new_size * sizeof(ptr[0]));
    // call malloc and output the new size
    // copy ptr over to the new_size
    int i;;
    for (i = 0; i < new_size; i++) {
        new_malloc[i] = ptrs[i];
    }
}

#ifndef TESTING
int main(void)
{
    // duplicate test
    char *s = "Some string to duplicate.";
    char *dup = string_dup(s);

    printf("Duplicated string: %s\n", dup);

    // mem copy test
    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int *target = malloc(n * sizeof(int));
    
    mem_copy(target, numbers, n * sizeof(int));

    printf("Copied array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", target[i]);
    }

    printf("\n");

    // resize memory test
    char *url = string_dup("http://lambdaschool.com");
    char *path = string_dup("/students/");
    int url_length = string_length(url);
    int path_length = string_length(path);
    
    int new_length = url_length - 1 + path_length;
    char *new_url = resize_memory(url, url_length, new_length);
    char *p = new_url + url_length;

    while (*path != '\0') {
        *p = *path;
        p++;
        path++;
    }

    printf("Full path string: %s\n", new_url);

    // return 0;
    EXIT_SUCCESS;
}
#endif