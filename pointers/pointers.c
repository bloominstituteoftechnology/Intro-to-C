#include <stdio.h>

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Pointer arithmetic
    is necessary here. Also, make sure x points to a null terminator at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{

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
    // printf("%p\n", *str);
    // printf("%s\n", str);
    // printf("%i\n", strlen(str));

    for(int i=0; i < strlen(str); i++) {
        // printf("%c\n", str[i]);
        if (c == str[i]) {
            return &str[i];
        };
    }

    return NULL;
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
    int nl = strlen(needle);

    for(int i=0; i < strlen(haystack); i++) {
        int matches = 0;

        for (int j=0; j < nl; j++) {
            if(haystack[i + j] == needle[j]) {
                matches = 1;
            } else {
                matches = 0;
                break;
            };
        }

        if (matches) {
            return &haystack[i];
        }
    }

    return NULL;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
