#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int charCount = 0, i = 0;
    int length = strlen(s);

    while (s[i] != 0)
    {
        if (s[i] != ' ')
        {
            charCount++;
        }
        i++;
    }
    return charCount;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
    int length = strlen(s);
    int i, x = 0;;
    for (i = length; i >= 0; i--) {
        rv[x] = s[i];
        x++;
        printf("CHARS: %d\n", rv[x]);
    }
    rv[length] = '\0';
    printf("REVERSED: %s\n", rv);
    return rv;
}
// char *reverse_string(char rv[], char s[])
// {
//     int length = strlen(s);
//     int count = 0;
//     int i;
//     for (i = length - 1; i >= 0; i--)
//     {
//         rv[count] = s[i];
//         count++;
//         printf("CHARS: %d\n", rv[count]);
//     }
//     rv[count] = '\0';
//     printf("REVERSED: %s\n", rv);
//     return rv;
// }

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
