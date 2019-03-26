#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s (as a pointer), return the number of 
    characters in the string.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s)
{
    // Iterating with a while loop until it finds '\0' to denote the end of a string array.
    int length = 0;
    while (s[length] != '\0'){
        length++;
    }
    return length;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char *rv, char *s)
{
    // Finding the length of the array
    int length = 0;
    while(s[length] != '\0'){
        length++;
    }

    // Assigning the length of the array - 1 and exclude 0 to the variable 'end'
    int end = length - 1;

    //While the For loop iterate upward on rv, End will decrement backward on s and assign its value to rv.
    for(int i = 0; i < length; i++){
        rv[i] = s[end];
        end--;
    }

    //Assigning the last value to '\0' to denote the end of a string array.
    rv[end] = '\0';

    printf("%s\n", rv);

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
    
