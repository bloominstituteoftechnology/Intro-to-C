#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
*/
int string_length(char s[])
{
    int i = 0;
    // for(i = 0; i != '\0'; i++);
    while(s[i] != '\0' ) i++;
    // printf("Length of string: %d", i);
   return i;
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

    // int length = string_length(s);


    // printf("%d\n", length);

    // int i = length - 1;
    // for(i; s[] != '\0'; --i) {
    //     rv[]
    // }

    int i;
    int j = 0;
    int length = string_length(s);
    for (i = length - 1; i >= 0; i--){
        rv[j++] = s[i];
    }
    rv[j] = '\0';
    return rv;
    //return 0;
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
    
