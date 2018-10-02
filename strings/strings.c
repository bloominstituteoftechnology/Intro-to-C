#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int i = 0; // start at index 0

    while (s[i] != '\0') { // while index does not equal null terminator
        i++; // increment i
    }

    return i; // return i
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
    int len = string_length(s); // get legth of string s using above function
    int j = 0; // set j to 0

    for (int i = len - 1; i >= 0; i--) { // initialize decrementing for loop
        rv[j++] = s[i]; // increment j in rv as i in s decrements
        // had this before
        // rv[j] = s[i]
        // j++
    }

    rv[len] = '\0'; // terminate the reversed string with a null character

    return rv; // return reversed array
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
