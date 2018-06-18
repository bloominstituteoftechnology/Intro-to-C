#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int c = 0;
    for (int i = 0; s[i]; i++) {
        c ++;
    }
    return c;
}

// prints all characters in array
void print_arr(char a[])
{
    for (int k = 0; k < 27; k++) {
        printf("%c", a[k]);
    }
    printf("\n");
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
    int j = 0;
    for (int i = string_length(s) - 1; i >= 0; i--) {
        rv[j] = s[i];
        j++;
    }
    print_arr(rv);
    return rv;
}




#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1)); // 26
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
    
