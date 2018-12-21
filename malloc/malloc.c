#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    char *dup = malloc(strlen(src));
    int i;
    for (i = 0; i < strlen(src); i++) {
        *(dup+i) = *(src+i); 
        // printf("%c\n", *(dup+i));
    }
    *(dup + strlen(src))='\0'; // QQQQQ?: Do I need this here? I think so but would like to make sure. 
    free(dup);
    return dup;
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
    // printf("dest size: %i, src size: %i", sizeof(dest), sizeof(src));
    // printf("dest: %p, src: %p", dest + 1, src+1);
    
    // QQQQQQ? casting input pointer to char pointer first. doesn't that change mean change dest from void to char?

    // // // ATTEMPT #1     QQQQQQ?: Don't understand why this didn't work
    // for (int i = 0; i < n; i++) {
    //     *(&dest + i) = *(&src +i);
    // }

    // // ATTEMPT #2
    char *cdest = dest;
    const char *csrc = src;

    for (int i = 0; i < n; i++) {
        *(cdest + i) = *(csrc +i);
    }    
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
    // ptr: pointer of type void that just malloc'd memory
    printf("size of input pointer: %d, size of input pointer data type: %d\n", sizeof(ptr),sizeof(ptr[0]));
    printf("size of old_size: %d, size of new_size: %d\n", sizeof(old_size),sizeof(new_size));

    // need to `re`-malloc ptr and pass in the new_size
    // if new_size> old_size, data will be intact in newly malloc'd ptr
    // if new_size< old_size, data will not stay intact

    char *cptr = ptr;
    if (new_size<old_size) {
        printf("Error: new_size < old_size, implying that data would be lost if this were to be carried out.\n");
    }
    if (new_size>=old_size) {
        // ptr = (void *) malloc(new_size);
        cptr = malloc(new_size);
    }
    *(cptr+new_size) = "\0"; 

    // for (int i = 0; i < sizeof(ptr);i++) {
    //     printf("%d\0",(ptr+i));
    // }
    printf("%d\0",sizeof(cptr));
    printf("cptr:%p (hex), %d (reg); ptr[0]:%p (hex), %d (reg)\0", cptr,cptr,ptr, ptr);
    printf("cptr:%p, *cptr:%p, ptr:%p\0", cptr,cptr,ptr);
    
    free(cptr);
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

    // while (*path != '\0') {
    //     *p = *path;
    //     p++;
    //     path++;
    // }

    // printf("Full path string: %s\n", new_url);

    return 0;
}
#endif
