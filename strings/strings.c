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
    
    for (int i = 0; s[i] != '\0'; ++i) 
    // increment counter for each element in array except '\0' -- null values
    {
        counter = counter + 1;
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
    int n = string_length(s); // using function above - get the length for iteration loop
    int index = 0; // create stating position for rv
  
    for (int i = n - 1; i >= 0; i--) //iterate backwards through s, starting at last element 
    {
        //set current position in rv array to the current index value of s array 
        rv[index] = s[i]; 
        index++; // move up one position in rv array (...as we're moving back one position in s)   
    }
    rv[index] = '\0';//terminate the reversed string with a null character
    return rv; // return reversed array 
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
    
