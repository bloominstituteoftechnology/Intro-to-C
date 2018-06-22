#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    printf("==> pointer s : %p\n", s);    // pointer address in ram
    printf("==> pointer s : %c\n", *s);   ///  value of the first element in array  which is the pointer itself
    printf("==> pointer s : %c\n", s[0]); //   value of first element in array ....................
    printf("==> value of pointer s is :%s\n", s);
    printf("==> & is the address of of s in the ram: %p \n", &s); //// variable s address in ram
    ///////////////////////////////////////////////////////////////////////
    int count = 0;
    while (s[count] != '\0')
    {

        printf("%c \n", *s);
        count++;
    }
    printf(" count is %d \n", count);
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
    int length = string_length(s);

    for (int i = 0; i < length; i++)
    {
        rv[i] = s[length - i - 1];
    }

    rv[length] = '\0';

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
