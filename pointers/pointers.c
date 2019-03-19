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
    // loop while the dereferenced y pointer does not equal null char
    while (*y != '\0')
    {
        // assign dereferenced x pointer to dereferenced y pointer
        *x = *y;
        // increment x pointer and y pointer
        x++;
        y++;
    };
    // due to last incrementation, x is in correct position, assign pointer x to null char
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
    // loop while dereference of str does not equal null char
    while (*str != '\0')
    {
        // if dereference equals c return pointer
        if (*str == c)
            return str;
        // increment str pointer
        str++;
    };
    // str now points to c
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
    // initialize a new pointer to the needle pointer
    char *beginN = needle;
    int found = 0;
    // while the deref haystack does not equal null char, increment
    while (*haystack != '\0')
    {
        // if deref haystack equals deref needle
        if (*haystack == *needle && found == 0)
        {
            // initialize new pointer to at haystack pointer
            char *beginH = haystack;
            // while value of beginH and beginN are equal and deref beginN does not equal null char
            while (*beginH == *beginN)
            {
                // increment beginN pointer
                beginN++;
                // increment beginH pointer
                beginH++;
                // if beginN equals null char
                if (*beginN == '\0')
                {
                    // change found to 1
                    found = 1;
                    // return haystack
                    return haystack;
                }
            }
            // reasign the needle pointer to beginN
            needle = beginN;
        }
        haystack++;
    }
    return NULL;
}

#ifndef TESTING
int main(void)
{
    char *hello = "Hello";
    char *world = "World";
    char buffer[1024];

    string_copy(buffer, "hello");

    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);
    printf("Copy of hello: %s\n", buffer);

    return 0;
}
#endif
