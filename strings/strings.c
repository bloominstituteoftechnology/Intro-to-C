#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int length = 0;
    int array_size = *(&s + 1) - s;
    printf("%d", array_size);
    // int array_size = sizeof(s) / sizeof(s[0]);
    // for (int i = 0; i < array_size; i = i + 1)
    // {
    //     length = length + 1;
    // }
    return array_size;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
    printf("%s", s);

    return s;
}

#ifndef TESTING
int main(void)
{
    // char quote1[] = "Don't forget to be awesome";
    char quote1[] = "hi";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
