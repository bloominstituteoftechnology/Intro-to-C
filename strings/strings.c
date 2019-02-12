#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int length = 0;
    //int array_size = sizeof(s) / sizeof(s[0]);
    int i = 0;
    // printf("Char size: %d\n", sizeof(s[0]));
    // printf("String (array) size: %d\n", sizeof(s));
    while (*(s + i) != '\0')
    {
        length = length + 1;
        i++;
    }

    return length;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
    int length = string_length(s);
    int j = 0;

    // do i need another string to save?
    //char *reversed_str = malloc(sizeof(char) * length);
    printf("%s", rv);
    for (int i = length; i >= 0; i--)
    {
        if (i == 0)
        {
            rv[j] = "\0";
        }
        rv[j] = *(s + i);
        j++;
    }

    return rv;
}

#ifndef TESTING
int main(void)
{
    // char quote1[] = "Don't forget to be awesome";
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    //printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
