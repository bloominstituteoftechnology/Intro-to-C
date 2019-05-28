#include <stdio.h>

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
    int length = 0;

    while (*(y + length) != '\0') {
        *(x + length) = *(y + length);
        length += 1;
    }

    *(x + length) = '\0';
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
    int check = 0;
    while (*(str + check) != '\0') {
        if (*(str + check) == c) {
            return str + check;
        }
        check += 1;
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
    int check = 0;
    int letter = 0;
    int isEnd = 0;

    while (*(haystack + check) != '\0') {
        if (*(haystack + check) == *(needle + letter)) {
            while (*(needle + letter) != '\0' && *(haystack + check + letter) != '\0') {
                if (*(needle + letter) != *(haystack + check + letter)) {
                    letter = 0;
                    break;
                } else if (*(needle + letter + 1) == '\0') {
                    isEnd = 1;
                }
                letter += 1;
            }
            if (isEnd) {
                return haystack + check;
            }
        }
        check += 1;
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
