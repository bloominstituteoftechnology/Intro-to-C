#include <stdio.h>
#include <string.h>

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Pointer arithmetic
    is necessary here. Also, make sure x points to a null terminator at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    int count = strlen(y);

    for (int i = 0; i < count; i++) 
    {
        x[i] = y[i];
    }

    x[count] = '\0';
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
    char *ptr = NULL;
    int len = strlen(str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c){
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
     while (1) {
        if (*haystack == *needle) 
        {
            for (char *p1 = haystack, *p2 = needle;;) 
            {
                if (!*p2)
                    return haystack;
                if (*p1++ != *p2++)
                    break;
            }
        }

        if (!*haystack++)
            break;
    }
    return NULL;

}


#ifndef TESTING
int main(void)
{
    char buffer[1024];
    char *hello = "hello";
    char *world = "world";

    string_copy(buffer, world);

    // If str copy works then this will print "world"
    printf("%s\n", buffer);   

    char *found_char = find_char(hello, 'e');

    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
