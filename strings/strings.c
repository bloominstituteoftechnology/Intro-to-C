#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int count = 0;
    char cur_char = s[count];

    while (cur_char != '\0')
    {
        count++;
        cur_char = s[count];
    }

    return count;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{   
    int len = strlen(s);
    int rv_index = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        rv[rv_index] = s[i];
        rv_index++;
    }
    
    return rv; //should return a pointer? so rv is address?  here be confusion
}

#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "tuba";

    char rv[512];
    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'tuba' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
    
