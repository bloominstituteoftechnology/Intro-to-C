#include <stdio.h>
#include <stdlib.h>

/*

    Given a character array s (as a pointer), return the number of 
    characters in the string.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s)
{
    int c = 0;

    while (s[c] != '\0')
    {
        c++;
    }
    return c;
}

/*
    Write a function that reverses the order of string s and outputs
    the reversed string to the input array rv. The rv array will have
    enough space for the reversed string. Don't forget to terminate
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char *rv, char *s)
{
    int length = string_length(s) - 1;
    int start = 0;
    for (int i = length; i >= 0; i--)
    {
        rv[start] = s[i];
        start++;
    }
    rv[start] = 0;
    return rv;
}

#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
