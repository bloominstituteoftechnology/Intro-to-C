#include <stdio.h>
#include <strings.h>

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Pointer arithmetic
    is necessary here. Also, make sure x points to a null terminator at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    for (; *y != '\0'; x++, y++) {
        *x = *y;
    }
    *x = '\0';
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
    int length = strlen(str);
    char *ptr = NULL;
    for (int i = 0; i < length; i++) {
        if (str[i] == c) {
            ptr = &str[i];
        }
    }
    return ptr;
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
    while (*haystack != '\0') {
        if (*haystack == *needle) {
            char *ptr = haystack;
            while (*haystack == *needle && *needle != '\0') {
                haystack++;
                needle++;
            }
            if (*needle == '\0') {
                return ptr;
            }
        }
        haystack++;
    }
 
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
