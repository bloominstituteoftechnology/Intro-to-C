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
    int counter = 0;

    for (int i = string_length(s) - 1; i >= 0; i--) 
    // go backwards from the string_length to start from the end
    // NOTE: we take strlen - 1 so we can terminate the reversed_str with a null character
    {
        rv[counter] = s[i]; // --> Here we can swap!
        /*
            rv || s
            This is if the word were 6 characters since the last character would be null
            None || '\0'
            0 || 5
            1 || 4
            2 || 3
            3 || 2
            4 || 1
            5 || 0

        */
        counter++;
    }

    rv[string_length(s)] = '\0'; // --> Terminate the reversed string with a null char
    return rv; // --> return rv array
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
    
