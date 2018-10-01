#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at. 
*/
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    while (*str != '\0') {
        if (*str == c) {
            return str;
        } else {
            str++;
        }
    }
    return str;
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
    
    Do not just use the `strcpy` function from the standard library.
*/
void string_copy(char *x, char *y)
{
    // while (*y != '\0') {
    //     *x = *y;
    //     x++;
    //     y++;
    // }
    // *x = '\0';
    for (unsigned long i = 0; i < (sizeof(x)/sizeof(char)); i++) {
        *x = *y;
        x++;
        y++;
    }
    *x = '\0';
}

/* 
    Compares the character strings m and n and returns negative,
    0, or positive if n is lexicographically less than, equal to,
    or greater than n. To calculate lexicographic difference, find
    the difference between the first characters in m and n that differ.
    
    For example, given matching strings, this function should 
    return 0. Given strings m = "hello world" and n = "goodbye",
    this function should return a positive value. Given strings
    m = "aardvark" and n = "zebra", should return a negative
    value.
    
    Do not just use the `strcmp` function from the standard library.
*/
int string_compare(char *m, char *n)
{
    while (*m != '\0' && *n != '\0') {
        if (*m > *n) {
            return 1;
        }
        else if (*m < *n) {
            return -1;
        }
        m++;
        n++;
    }
    return 0;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    char empty[3];
    printf("SIZE %lu\n", sizeof(empty));
    printf("OTHER SIZE %lu\n", sizeof(haystack));
    string_copy(empty, haystack);
    printf("HERE %s\n", empty);
    // while (*haystack != '\0') {
    //     if (*haystack == *needle) {
    //         char *found = haystack;
    //         while (*needle != '\0') {
    //             needle++;
    //             printf("1 %c\n", *needle);
    //             haystack++;
    //             printf("2 %c\n", *haystack);
    //             if (*needle != *haystack) {
    //                 return "Not found";
    //             }
    //         }
    //         return found;
    //     }
    //     haystack++;
    // }
    // return "Not fooound";
}

#ifndef TESTING
int main(void)
{
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);

    char *hello = "Hello";
    char *world = "World";
    char buffer[1024];

    string_copy(buffer, hello);

    printf("Buffer is %s\n", buffer);
    printf("Comparison is %d\n", string_compare(hello, world));

    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
