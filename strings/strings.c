#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    printf("\n%s", s);
    int length = 0;

    while (s[length] != '\0')
    {
        length++;
    }
    printf("\nLength: %d\n", length);
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
    // printf("RV %s %d END", rv, string_length(rv));
    int length = string_length(s);
    // int reverse_length = length * sizeof(char) + 1;
    // char rev[reverse_length];
    // char rev[length - 1];

    int i = 0;

    while (i < length)
    {
        rv[length - 1 - i] = s[i];
        i++;
    }
    rv[length] = '\0';
    // printf("%s\n%s\n", s, rv);
    // printf(string_length(rv));
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
