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
    /* get length of the input string
    assign a pointer char variable to reference memory allocation to that length block of variable type char
    loop through the entire length and assign each letter from src to the new variable
    return this
    */

    int length = strlen(src);
    char *point = malloc(length * sizeof(char));
    
    for(int i = 0; i < length; i++) {
        point[i] = src[i]; /* this should copy the values at particular references in point */
    }
    printf("%s\n%s", point, src);
    return point;
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
    /* similar to the string_dup solution, make storage for both the source and a copy
    point the copy to dest so that the value is assigned
    loop in a similar fashion to previous answer and copy entries
    */

    char src_copy = (char *)src;
    char *dest_copy = dest;

    for(int i = 0; i < n; i++) {
        dest_copy[i] = src_copy[i];
    } /* will handle general copying */
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
    /* create a new variable and malloc it with the new_size and another byte for null terminator
    reference the initial pointer with another variable 
    create another variable that handles size
    when old_size < new_size, assign new size variable to old size
    if this is not the case, assign new size variable to new size
    loop and perform a similar copying operation to above examples
    set the old pointer to the new so it references the proper block of memory
    */

    char *ptr_copy = malloc(new_size + 1);
    char *storage = (char *)ptr;
    int size;

    if(old_size < new_size) {
        size = old_size; /* handle the provided edge case */
    }
    else {
        size = new_size; /* else, proceed as normal */
    }
    
    for(int i = 0; i < size; i++) {
        ptr_copy[i] = storage[i]; /* same copying logic as previous problems */
    }
    ptr = ptr_copy; /* referencing the newly populated memory block */

    return ptr;
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