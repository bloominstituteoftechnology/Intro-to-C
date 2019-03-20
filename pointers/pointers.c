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

    if (*x == '\0')
    {
        *x = *y;
    }
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
    while (*str != '\0')
    {
        if (*str == c)
        {
            return str;
        }
        str++;
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

// char *a = "[H][e][l][l][o]"

// int num = 3

char *find_string(char *haystack, char *needle)
{
    // initialize an empty pointer to ref the haystack pointer
    char *hayPointer;
    // while the haystack
    while (*haystack != '\0')
    {
        // set the hayPointer to the haystack
        hayPointer = haystack;
        // check if the current haypointer iteration matches the needle
        if (*hayPointer == *needle)
        {
            // while the needle is not 0
            // we do this stop the haystack
            // and check all the characters in the needle,
            // otherwise it will only check the first character
            while (*needle != '\0')
            {
                // if it is not a match then
                // we need to break out of the loop
                // or it will go forever
                if (*hayPointer != *needle)
                {
                    break;
                }
                //increment both hayPoint and needle
                hayPointer++;
                needle++;
                // if the needle equals NULL then return the haystack
                if (*needle == '\0')
                {
                    return haystack;
                }
            }
        }
        // increment the haystack so that it
        // moves the while loop
        // after all other ops end
        haystack++;
    }

    return NULL;
}

#ifndef TESTING
int main(void)
{
    char *hello = "hello";
    char *world = "world";
    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
