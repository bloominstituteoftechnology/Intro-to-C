#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
*/
int string_length(char s[])
{
    int count = 0;
    while ( s[count] != '\0') {
        ++count;
    }
    // printf("%d\n", count);
    return count;
}

/*
    Don't worry about this funky 'char *' going on here. We'll get to
    that shortly. In the meantime, write a function that reverses the 
    order of string s and outputs the reversed string to the input 
    array rv. The rv array will have enough space for the reversed 
    string. Don't forget to terminate the reversed string with a null
    character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
    // printf("%s\n", s); // %s prints str
    int length = string_length(s);
    int count = 0;
    for (int i = length - 1; i >= 0; i--) {
        // printf("%c\n", s[i]);
        rv[count] = s[i];
        ++count;
    }
    rv[count] = '\0';
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
    
