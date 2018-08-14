#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it. Dont count the null terminator(\0)
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    // init a counter
    int counter = 0;
    // while the counter isn't the end of the string,
    // increment the counter for each char
    while (s[counter] !='\0')
    {
        counter ++;
    }
    // return the counter
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
    // init a count, which is used as an index in the return value
    int count = 0;
    // get the length of the string from the function we just wrote
    int len = string_length(s);
    // loop over the string, incrementing the count as you do
    // this is basically a normal for loop in reverse
    for(int i=len-1; i>=0; i--)
    {
        // first element in RV is the last value of s
        rv[count++] = s[i];
    }
    //stop when we hit the null terminator
    rv[len] = '\0';
    //return the return value
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
    
