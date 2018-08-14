#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int counter = 0;           // initialize a counter variable
    while (s[counter] != '\0') // while the value at the counter-th index of the string array is not equal to the null character, increment counter, and compare again until null character is found.
    {
        counter++; // increment counter
    }
    return counter; // returns counter value to be used in the prinf on line 38
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
    // calculate the length of a string using the function from above that does this
    int length = string_length(s);

    // initialize variable end to be equal to length - 1. Will be used to signify the end index position of string s
    int end = length - 1;

    for (int i = 0; i < length; i++)
    {
        // copying the characters in reverse order (from the end of string s to the beginning) to a new char array rv (from the beginning of the rv array) using a for loop
        rv[i] = s[end];
        // decrementing the value of end until s[end] is at the beginning of the string
        end--;
    }
    // terminating the reversed string by assigning the null character
    rv[length] = '\0';

    // return the reversed string 'amanap lanac a nalp a nam a'
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
