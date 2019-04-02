#include <stdio.h>
#include <string.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    int len = strlen(y);
    for (int i = 0; i < len; i++){
        x[i] = y[i];
    }
        x[len] = '\0';

    printf("printing x: %s\n", x);
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
    char *p;

    for (unsigned long i = 0; i < sizeof(*str); i++){
        if (str[i] == c){
            p = &str[i];
        }
    }
    return p;
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
    char *pointer;
    int length = strlen(haystack);
    // create a for loop and iterate through haystack
    for (int i = 0; i < length; i++){
        // while looping through haystack if it match the first index of needle
        if (haystack[i] == needle[0]){
            pointer = &haystack[i];
            int j = 0;
            // then set a second loop and iterate through needle along with haystack to ensure from beginning to end it'll match.
            while (needle[j] != '\0'){
                // If true, then return the pointer that reference haystack[i] that matches initially.
                if (haystack[i] == needle[j]){
                    // printf("%c\n", needle[j]);
                    i++;
                    j++;
                }
                else {
                    return 0;
                }
            }
            return pointer;
        }
    }
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
