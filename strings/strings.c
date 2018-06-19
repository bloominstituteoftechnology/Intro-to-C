#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    // set up a count variable
    int count = 0;
    // iterate over the passed in array
    for (int i=0;s[i];i++){
        //increment count
        count ++;
    }
    // return count
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
    //declare variables, for the indexes.  
    int j =0;  
    //call string_length passing in the s array
    int strLength = string_length(s);
    // itereate over s array decrmenting
    for( int i = strLength; i>=0;i--)
{
    // set rv at index j = s and index at i
rv[j] = s[i - 1];
//increment variable
j++;
}
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
    
