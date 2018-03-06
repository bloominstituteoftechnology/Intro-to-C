#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    Given a character array s, return the number of characters 
    held inside it.
*/
int string_length(char s[])
{
    int length = 0;
    while(s[length] != '\0'){
        length++;
        printf("The current len is %d\n", length);
    };
    return length;
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
    int len = string_length(s);
    for(int i = len-1 ; i >=0; i--){
        rv[len-1-i] = s[i];
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
    
