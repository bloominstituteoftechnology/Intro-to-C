// Header file for Standard Input Output
    // contains printf() and scanf()
    // contains header info for 'File related Input/Output' functions
    // ("As  a basic principle, in C (due to its association with UNIX history), keyboard and display are also treated as ‘files’! ")
#include <stdio.h> 
// Header file for Standard Library.
    // contains malloc() and free()
    // contains header info for 'Memory Allocation/Freeing' functions
#include <stdlib.h>  

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/

int string_length(char s[]) // declares s to be an array holding values of type char
{
    int i;

    while (s[i] != '\0') // The '\0' is the null character. It's put at end of array to mark the end of the string of chars.
        ++i;
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
    // // first reverse the order of string s
    // // how do you reverse the order of a string? 
        // // you first get its length
    
    int length;
    length = string_length(s); 

    // // you want to iterate from the size of the string length to zero,
       // // meaning that, string[stringlength or stringlength-1 if the '\0' is included in the length]
       // // the first letter in the reversed string is the last letter in the non-reversed string (i.e. reversed[0] = nonreversed[length-1])
       // // and then you subtract one from the counter until the zero indexed string character in the nonreversed string is returned as the last indexed string in the reversed string    
    
    // printf("%d\n", length);
    // printf("%s\n", s);

    int i; 
    for (i = 0; i < length; i++) 
        rv[i] = s[length-1-i];
    // the last character in the reversed string is not a letter, but a '\0' signifying that the string should be terminated
    rv[length] = '\0';
    // printf("%s\n", rv);    
    
    // //return the rv array
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
    
