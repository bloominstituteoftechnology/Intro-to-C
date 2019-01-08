#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
    
    Do not use the `strdup` function from the standard library.
*/
char *string_dup(char *src)
{
    int length = string_length(src) + 1; // use length + 1 to account for null pointer
    char *new_string = malloc(length * sizeof(char)); 

    for(int i = 0; i < length; i++){
        new_string[i] = src[i];
    }

    return new_string;

}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).
    `n` is the number of bytes to copy. You may want to cast the input 
    pointers to char pointers first before performing the copying. 
    
    Do not use the `memcpy` function from the standard library.
*/
void *mem_copy(void *dest, const void *src, int n)
{
    // function copies n chars from src to dest
    char *char_src = (char*)src; // recast the src as char

    char *char_dest = (char*)dest;
    
    for(int i = 0; i < n; i++){
        char_dest[i] = char_src[i];
    }

    return char_dest;
}

/*
    Given a pointer that `malloc`'d memory, this function will 
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
    char *new_mem = malloc(new_size); // malloc a new chunk of memory

    char *data = ptr; // store the previously malloc'd data

    for(int i = 0; i < old_size; i++){
        if(i == new_size){
            break; // end the loop if we reach the new size limit
        }

        new_mem[i] = data[i]; // copy the old malloc'd data into the new malloc'd memory
    }
    return new_mem;
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

    return 0;
}
#endif
