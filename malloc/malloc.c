#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <string.h>

int string_length(char *s)
{
  return strlen(s);
}

// int string_length(char *s)
// {
//   char current = s[0];
//   int len_str = 0;
//   while (s[len_str] != '\0') {
//     len_str++;
//   }
//   return len_str;
// }
/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
*/
char *string_dup(char *src)
{
    char * outstr = (char*) malloc(sizeof(char) * strlen(src)+1);
    for (int i = 0; i < strlen(src); i++) {
        outstr[i] = src[i];
    }
    outstr[strlen(src) ] = '\0';
    // printf("dupped str: %s ", outstr);
    return outstr;
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
    // type cast to char
    char * chardest = (char*) dest;
    char * charsrc = (char*) src;
    // get num chars from bytes
    int length = n / sizeof(char);
    // copy values
    for (int i = 0; i < length; i++) {
        chardest[i] = charsrc[i];
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
    char * old_mem = (char*) ptr;
    if (new_size > old_size) {
        char * new_mem = malloc(new_size * sizeof(char));
        // copy old_mem into new_mem
        for (int i = 0; i < old_size; i++) {
            new_mem[i] = old_mem[i];
        }
        ptr = new_mem;
    } else if (new_size < old_size) {
        // only copy up to new_size
        char * new_mem = malloc((new_size+1) * sizeof(char));
        for (int i = 0; i < new_size; i++) { // 
            new_mem[i] = old_mem[i];
        }
        new_mem[new_size+1] = '\0';
        ptr = new_mem;
    }
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
    
    mem_copy(target, numbers, sizeof(numbers));

    printf("Copied array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", target[i]);
    }

    printf("\n");

    char *url = string_dup("http://lambdaschool.com");
    char *path = string_dup("/students/");
    int url_length = string_length(url);
    int path_length = string_length(path);
    printf("lengths %d %d \n", url_length, path_length);
    
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