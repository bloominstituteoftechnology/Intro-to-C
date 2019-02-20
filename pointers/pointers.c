#include <stdio.h>

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Pointer arithmetic
    is necessary here. Also, make sure x points to a null terminator at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    while(*y != '\0')
    {
        //copying contents of y over to x
        *y = *x;
        //iterate through both
        x++;
        y++;
    }
    //terminating properly with x pointing to null terminator
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
    //while str is not null
    while (*str != '\0') 
    {
        //loop through checking every character against c, 
        if (*str == c)
        {
            //if find the char you're looking for return
            return (str);  
            //why return str for c? bc already know char were searching for 
            //so that could just return bool this way we return a pointer which could be more useful
        }
        //iterate through str
        str++;
    }
    //better than returning 0 since supposed to return pointer
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
    while (*haystack != '\0')
    {
        char *point_to_needle = needle;
        if (*haystack == *needle) 
        {
            //assign new pointer bc have to return pointer
            char *point_to_haystack = haystack;
            while (*needle == *haystack && *needle != '\0')
            {
                needle++;
                haystack++;
            }
            if (*needle == '\0')
            {
                return point_to_haystack;
            }
            needle = point_to_needle;
        }
        //continually increments haystack if no matches
        haystack++;
    }
    return NULL;
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
