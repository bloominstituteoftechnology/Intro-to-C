#include <stdio.h>
#include <stdlib.h>

//define funcs;
int string_length(char s[]);
char *reverse_string(char *rv, char *s);
/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/

#ifndef TESTING
int main(void){
    char quote1[] = "Don't forget to be awesome!";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The quote is this: '%s'.\n The length is this: %d\n.", quote1, string_length(quote1));
    printf("Here is this quote: %s.\n This is the quote reversed: %s\n", quote2, reverse_string(rv, quote2));

    return 0;
}
#endif
//initiate funcs
//tell what the funcs do. 

int string_length(char s[]){
int length = 0;
    while (s[length] != '\0'){
        length += 1;
    }
    printf("length: %d\n", length);
    return length;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[]){
    int len = string_length(s);
    int i;
    int j = 0;
    for(i = len-1; i >= 0; i--){
        rv[j] = s[len - i]; 
        j++;
    }
    rv[len] = '\0';
    return rv;
}


