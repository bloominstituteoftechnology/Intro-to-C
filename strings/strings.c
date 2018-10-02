#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{	   
    //Initialze the length
    int count = 0;
    while(*s != '\0')
    {
        count++;
    }
    printf("\n%d\n", count);
    return count;

    // int len = 0;
    //Using Pointer Arithmentic:
    //Start at 0, while the value to what it's pointing to is NOT 0, keep going
    // for (int i=0; *(s+i) != 0; i++ )
    // {
    //     len++;
    // }
    //Using Arrays
    // for (int i=0; s[i] != 0; i++ )
    // {
    //     len++;
    // }
    // return len;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{	
    while(*s != '\0')
    {
        int len = string_length(s);
        for (int i = 0; i < len; i++)
        {
            rv[i] = s[len - 1 - i];
        }
        rv[len] = '\0';
        return rv;
    }
    
    // for (int i=string_length(s)-1; i >= 0; i--) {
    //     rv[string_length(s)-i-1] = s[i];
    // }
    
    // rv[string_length(s)] = '\0';
    
    // printf("reverse string: %s",rv);
    
    // return rv;	
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