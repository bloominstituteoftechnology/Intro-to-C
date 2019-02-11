#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
    strlen with include spaces and other characters.
*/
int string_length(char s[])
{
    int count = 0;
    
//    // Notice we don't have a "condition" in the loop. We actually don't know how long the string is, so we will have to loop forever, until the last character is 0 (NULL).
    // This counts only leters/
//    for (int index = 0; ; index++) {
//        char character = s[index];    // Get the character out from the pointer
//        
//        if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z')) { 
//            count += 1; 
//        } else if (character == 0) {
//            break;
//        }
//    }
    
    for (int index = 0; ; index++) {
        char character = s[index];    // Get the character out from the pointer
        
        if (character == 0) {
            break;
        } else {
            count += 1;
        }
    }
    
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
    /*
    hello
    5-0-1 = 4 'h' goes to index 4
    5-1-1 = 3 'e' goes to index 3
    */
    
    int count = strlen(s);
    
    for (int index = 0; index < count; index++) {    // looping count number of times
        char character = s[index];
        
    /* 
    If there is no condition, we can check when the last character is 0, and stop the loop
    This check needs to be before rv[...] because when the character is null, that means the index is 5, so adding it up (5 - 5 - 1 = -1), so we are modifying the memory at pointer -1, which is whatever is before rv pointer.
    */
//        if (character == 0) {
//            break;
//        }
    
        rv[count - index - 1] = character;
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
    
