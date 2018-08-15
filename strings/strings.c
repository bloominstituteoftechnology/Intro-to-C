#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int n = 0; // set a variable n which will be an index and counter

    while (s[n] != '\0') { // using while loop, iterate n times as much as the number of elements in the array until the condition meets '\0', the null character
        n++; // at each iteration, add 1 to n
    }

    return n; // When the iteration is over, return n which now has how many time the code was iterated. In other words, n represents how many elements the array has
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
    int count = 0; // set a variable count which will be a counter and index
    int len = string_length(s); // using the function set above, count the lengh of the input string and store in variable 'len'

    for (int i = len - 1; i >= 0; i--) { // iterate code 'len' times backward from end of array using for loop
        rv[count++] = s[i]; // Read elements in s[] one by one from the end, assign them in rv[] one by one from the front
    }

    rv[len] = '\0'; // add null character at the tail of rv[] array to mark the end of the array.
    return rv; // return the reversed array rv
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
    
