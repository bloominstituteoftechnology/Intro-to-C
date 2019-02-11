#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int counter = 0;

    while (1)
    {
        if (s[counter])
        {
            counter++;
        }
        else
        {
            break;
        }
    }
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
    int total;
    int count = 0;
    printf("%s \n", s);
    total = string_length(s);
    while (1)
    {
        if (total == 0)
        {
            rv[count] = '\0';
            break;
        }
        rv[count] = s[total - 1];
        count++;
        total--;
        }
    printf("%d", string_length(rv));
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