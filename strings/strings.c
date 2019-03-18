#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    // initialize length variable
    int length = 0;
    // for loop that loops through the string until it his the \0 special char
    for (int i = 0; s[i] != '\0'; i++)
    {
        // increment length
        length++;
    };
    // return length
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
    // initialize length, begin and end variable to 0
    int length, begin, end = 0;
    // loop through until the value of string array is \0 char
    while (s[length] != '\0')
        // increment the length variable
        length++;
    // update the end int variable to be length -1
    end = length - 1;
    // loop through the length of s array, increment begin
    for (begin = 0; begin < length; begin++)
    {
        // assign the value of rv[begin] to the value of the s array at index end
        rv[begin] = s[end];
        // decrement end
        end--;
    };
    // reassign the value of rv at index of begin which is the last index, to the null char
    rv[begin] = '\0';
    // return the rv array
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
