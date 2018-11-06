#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    // \0
    int count = 0;
    // printf("s => %c \n", s[26]);
    for (int i = 0; ; i++){
        if(s[i] == '\0'){
            return count;
        }
        count += 1;
        // printf(" %d -- %c\n", count, s[i]);
    };
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/

char *reverse_string(char rv[], char s[])
{
    // printf("3 => %d\n", string_length(s));
    int len = string_length(s);
    // *rv = s[len-1];
    char new[len]; 
    for(int i = 1; i < len+1; i++){
        // printf("3 i => %d\n", i);
        // printf("3 s[len] => %c\n", s[len-i]);
        new[i-1] = s[len-i];
        printf("3 new => %s\n", new);
    }
    new[len] = '\0';
    rv = new;
    printf("4 =>%s<=\n", rv);
    printf("4 =>%s<=\n", string_length(rv));
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
    
