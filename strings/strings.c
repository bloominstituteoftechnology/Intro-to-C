#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int i = 0;
    char ch;

    ch = s[i];

    while(ch != '\0'){
        i++;
        ch = s[i];
    }

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
    int len;
    int i;
    int j;
    char ch1;

    len = string_length(s);
    ch1 = s[len];
    j = 0;
    
    for( i = len; i >=0 ; i--)
    {
        rv[j] = ch1;
        ch1 = s[i];
        j++;
    }
    

    return rv;

}

#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters including spaces.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
    
