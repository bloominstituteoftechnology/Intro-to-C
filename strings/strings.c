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
    int index = 0;
    int count = 0;

    while(s[index])
    {
        if (s[index] >= 'a' && s[index] <= 'z')
            count++;

        if (s[index] >= 'A' && s[index] <= 'Z')
            count++;

        index++;
    }
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
    int index = 0;
    int count = 0;
    while(s[index])
    {
        if (s[index] >= 'a' && s[index] <= 'z')
            count++;
        if (s[index] >= 'A' && s[index] <= 'Z')
            count++;
        index++;
    }
    printf("count is %d \n", count);
    printf("why no print?\n");

    for (int j = count; j > 0; j--)
    {
        printf("count is %d\n", j);
    }
//    end = count - 1;
 
//    for (begin = 0; begin < count; begin++) {
//       r[begin] = s[end];
//       end--;
//    }
 
//    r[begin] = '\0';
 
//    printf("%s\n", r);
 
   return 'a';
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
    
