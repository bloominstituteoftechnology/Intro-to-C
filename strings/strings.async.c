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
    int counter = 0;
    int found = 0;

    while (found == 0)
    {
        char str = s[counter];
        if (str == '\0')
        {
            found = 1;
        }
        else 
        {
            counter++;
        }
    }

    return counter;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
    int index = 0;
    int s_len = strlen(s);
    for (int j = s_len - 1; j >= 0; j--) {
        rv[index] = s[j];
        index++;
    }
    
    return rv;
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
    
