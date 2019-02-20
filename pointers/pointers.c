#include <stdio.h>
#include <stdlib.h>

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Pointer arithmetic
    is necessary here. Also, make sure x points to a null terminator at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    for(int i = 0; y[i] != '\0'; i++) {
        x[i] = y[i];
    }
    return x;

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
    for (int i = 0; str[i] != "\0"; i++) {
        if (str[i] == c) {
            int p = &str[i];
            return *p;
        }
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
    int length = sizeof(needle)/sizeof(char);
    for (int i = 0; haystack[i] != '\0'; i++) {
        if(haystack[i] == needle) {
            int p = &haystack[i];
            return *p;
        }

    }
    return 0;

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
