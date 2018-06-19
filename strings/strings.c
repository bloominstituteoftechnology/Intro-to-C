#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int i = 0;
    
    while (s[i] != '\0') {
        i++;
    }

    return i;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
    int sLen = string_length(s);
    int counter = 0;
    for (int i = sLen - 1; i >= -1; i--) {
        rv[counter] = s[i];
        counter++;
    }
    return rv;
/*****************Jacob's doo doo code******************************/
    // //declare variables, for the indexes.    
    // //call string_length passing in the s array
    // int strLength = string_length(s);
    // int j = 0;
    // // itereate over s array decrmenting
    // for (int i = strLength; i >= 0; i--) {
    //     // set rv at index j = s and index at strLength
    //     rv[j] = s[i - 1];
    //     //increment variables
    //     j++;
    // }

    // return rv;
/****************Eric's Doo Doo code****************************/

    // int j = 0;
    // for (int i = string_length(s) - 1; i >= -1; i--) {
    //     rv[j] = s[i];
    //     j++;
    // }
    // printf("%s\n", rv);
    // return rv;

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
    
