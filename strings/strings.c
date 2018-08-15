#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int n = 0;              // initialize n to start at first index in the array

    while (s[n] != '\0') { //while loop that if n has not reached the null terminator 
        n++;               // n will keep incrementing
    }
    return n;              // return n
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
    int count = 0;  // initialize a count starting at index 0
    int len = string_length(s); // get length of string that we're reversing using the previous string_length function

    for (int i = len - 1; i >= 0; i--) {  // reverse for loop to add the characters one by one backwards
        rv[count++] = s[i]; // after indexing into the array, increment count; the first element in rv is the last element in s  
    } 

    rv[len] = '\0'; // null terminator to terminate the string
    return rv;      // return rv
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
    
