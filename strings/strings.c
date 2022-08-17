#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s (as a pointer), return the number of 
    characters in the string.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s)
{
    int i = 0;

    // while (s[n] != '\0') {
    //     n++;
    // }    

    while (*(s+i) != '\0') { 
        i++;
    }
    return i;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char *rv, char *s)
{
    int reverseReverse = string_length(s);
    int newIndex = 0;
    for (int i = reverseReverse - 1; i >= 0; i--) {
        rv[newIndex] = s[i];
        newIndex++;
    }
    rv[reverseReverse] = '\0';
    return rv;
}

// char *reverse_string(char rv[], char s[])
// {
//     int count = 0;
//     int n = string_length(s);

//     for (int i = n - 1; i >= 0; i--) {
//         rv[count++] = s[i];
//     }

//     rv[n] = '\0';
//     return rv;
// }

char *reverse_string(char *rv, char *s)
{
    int count = string_length(s);
    int i = 0;
    while (count >= 1) { 
        count--;
        *(rv + i) = *(s + count);
        i++;
    }
    *(rv + i) = '\0';
    printf("%s\n", rv);
    return rv;

}

// char *reverse_string(char *rv, char *s)
//     {
//         char temp;
//         int n = string_length(s);

//         for (int i = 0; i < n/2; i++) {
//             temp = s[i];
//             s[i] = s[n-i-1];
//             s[n-i-1] = temp;
//         }
//         return temp;
//     }


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