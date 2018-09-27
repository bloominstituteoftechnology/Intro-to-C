#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int len = 0;
    for(int i = 0; s[i] != '\0'; i++ ) {
        len++;
    }
return len;
// return printf("%d", len);
// return printf("%c", s[0]);
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/

char *reverse_string(char rv[], char s[]){
    int len = string_length(s);
    for (int j = 0; j <= len; j++) {
        printf("%c", s[j]);    
    }
    for (int i = len; i >= 0; i--) {
        printf("%c", s[i]);
    }
}
// char *reverse_string(char rv[], char s[])
// {
//     int total_len = string_length(s); //26
//     int change_len = string_length(s); //26
//     int count = 0;

//     // rv[0] = 'd';
//     // rv[1] = 'u';
//     // rv[2] = 'm';
//     // rv[3] = 'b';
//     // rv[5] = '\0';

//     while(count <= total_len) {
//         rv[count] = s[change_len];
//         count++;
//         change_len--;
//     }
//     // total_len++;
//     rv[total_len] = '\0';
//     return rv;
//     // rv[(len+1)] = '\0';
//     // for (int i = 0; i <= len; i++) {
//     //     printf("%c", rv[i]);
//     // }
//     // printf("%s", rv);
//     // for (int i = len; i > 0; i--) {
//     //     for ( int j = 0; j < len; i++) {
//     //         printf("%c\n", s[i]);
//     //         rv[j] = s[i];
//     //     }
//     // }   
//     // rv[len] = '\0';
//     // return rv;
// }

// int main(void) {
//     char string[] = "word";
//     char rv[512];
//     reverse_string(rv, string);
// }

// #ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "Sa man a plan a canal panamaE";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    // printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));
    reverse_string(rv, quote2);
    // printf("%s\n", reverse_string(rv, quote2));
    return 0;
}
// #endif
    
