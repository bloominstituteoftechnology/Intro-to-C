#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    // make a counter variable
    int c = 0;
    // while the index of s[] is not the end of the array, increment the counter by 1
    while (s[c] != '\0') c++;
    // return the counter
    return c;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
    // declare a variable for the s[] length and a placeholder for the reverse str
    int strLen = string_length(s);
    int reverseStr = 0;
    // counter variable for loop
    int i;
    // loop over each index in string s
    for (i = strLen - 1; i >= 0; i--) {
            // set the index at position reverseStr within rv to the index of i within s, then increment 
            rv[reverseStr++] = s[i];
            rv[reverseStr] = '\0';
        }     
    // return 
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
    
