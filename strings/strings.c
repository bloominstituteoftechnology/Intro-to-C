#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int counter = 0;
    while(s[counter] != '\0')
    {
        counter++;
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
    int length = string_length(s) - 1;
    int new_length = 0;
    // printf("%d\n", length);
    while(length >= 0)
    {
        // printf("Length inside while %d\n", length);
        // printf("s[length] inside while %c\n", s[length]);
        rv[new_length] = s[length];
        length--;
        new_length++;
    }
    
    rv[new_length] = '\0';
    // printf("rv %s\n", rv);
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
    
