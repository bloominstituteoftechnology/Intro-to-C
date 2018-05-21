#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
*/
int string_length(char s[])
{
    int i = 0;
    for (i = 1; s[i] != '\0'; i++)
    {
        printf("Found integer %d at %u\n", i);
    };
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
    
    // Main Solution:
	int rvlength = string_length(s);
	int index = 0;

	for (int i = rvlength - 1; i >='\0'; i--) { // #QUESTION: Why is this base case working?
	  rv[index] = s[i];
	  index++;
	}
	rv[index] = '\0';

    // ===== Prints all characters in s 'array' ===== //
    for (int i = 0; i <= rvlength - 1; i++)
    {
        printf("Next pointer in s: %c\n", *(s + i));
        // printf("with machine address: %x\n", rv);
    }

    // ===== Prints all characters in rv 'array' ===== //
    for (int i = 0; i <= rvlength - 1; i++)
    {
        printf("Next pointer in rv: %c\n", *(rv + i));
        // printf("with machine address: %x\n", rv);
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
