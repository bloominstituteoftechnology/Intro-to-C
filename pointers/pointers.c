#include <stdio.h>
#include <string.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int* a, int* b)
{
    //so here, int* a is the value that the pointer a references, and likewise for b
    //we want the pointer a to point to the value *b
    //we want the point b to point to the value *a

    int a_postswap;
    int b_postswap;

    a_postswap = *b; // a_postswap (variable of type int) is set to the integer value pointer b is pointing to
    b_postswap = *a;

    *a = a_postswap; 
    *b = b_postswap;
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (*(str+i) == c) {
            // printf("%d\n", i);  // prints value of counter i in which int c is encountered
            // printf("%p\n", &str[i]); // prints the address of pointer pointing towards first match to int c
            return &str[i];
        }
        if (*(str+i) == '\0') {
            return 0; //QQQQQQQ? Should I be returning zero here if/when function reaches end of string without finding a match
        }
    }
}  


/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
    
    Do not just use the `strcpy` function from the standard library.
*/
void string_copy(char *x, char *y)  //buffer , hello
{
    int i = 0;

    while (*(y+i) != '\0') {
        *(x+i) = *(y+i);
        printf("%c\n", *(y+i));
        i++;
    }

    *(x+i+1) = '\0';     
}


/* 
    Compares the character strings m and n and returns negative,
    0, or positive if n is lexicographically less than, equal to,
    or greater than m. To calculate lexicographic difference, find
    the difference between the first characters in m and n that differ.
    
    For example, given matching strings, this function should 
    return 0. Given strings m = "hello world" and n = "goodbye",
    this function should return a positive value. Given strings
    m = "aardvark" and n = "zebra", should return a negative
    value.
    
    Do not just use the `strcmp` function from the standard library.
*/
int string_compare(char *m, char *n)
{
    int i;
    for (i = 0; i < strlen(m); i++) {
        if (*(n+i) > *(m+i)) {
            return 1;
        }
        if (*(n+i) < *(m+i)) {
            return -1;
        }
        if (*(n+i) == *(m+i) && i == strlen(m)-1 && strlen(m) == strlen(n)) {
            return 0;
        }
        if (*(n+i) == *(m+i) && i == strlen(m)-1 && strlen(m) < strlen(n)) {
            return 1;
        }
        if (*(n+i) == *(m+i) && i == strlen(m)-1 && strlen(m) > strlen(n)) {
            return -1;
        }
    }

}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{

}

#ifndef TESTING
int main(void)
{
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);

    char *hello = "Hello";
    char *world = "World";
    char buffer[1024];

    string_copy(buffer, hello);

    printf("Buffer is %s\n", buffer);
    printf("Comparison is %d\n", string_compare(hello, world)); // output = 1
    
    // // CUSTOM TEST for string_compare
    // char *zello = "Zello"; 
    // char *worldwide = "Worldwide"; 
    // printf("Comparison is %d\n", string_compare(zello, world)); // (output = -1)
    // printf("Comparison is %d\n", string_compare(worldwide, world)); // (output = -1)
    // printf("Comparison is %d\n", string_compare(world, worldwide)); // (output = 1)
    // printf("Comparison is %d\n", string_compare(worldwide, worldwide)); // (output = 0)

    char *found_char = find_char(hello, 'e');
    // char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    // printf("Found string: %s\n", found_string);

    return 0;
}
#endif













// ////////////////// FAILED ATTEMPT TO REVIEW LATER ///////////////////
// /*
//     Searches the input string `str` for the first instance of the 
//     character `c` (an unsigned char). This function returns a pointer
//     that points to the first instance of the character `c` in the
//     input string `str`.

//     Do not use the `strchr` function from the standard library.
// */
// char *find_char(char *str, int c)  // **Q: Why is the second argument of type int? -->
// // "A character constant is an integer, written as one character within single quotes
// // such as 'x'. The value of a character const is the numeric value in the machine's 
// // character set." It only takes up one bit. We use int here instead of char because
// // type c doesn't put aside enough bytes handle the number of bytes required to
// // write the EOF (End of File) and save. 

// // The character constant '\0' represents the char with value zero, the null charac.

// // "Be careful to distinguish b/t a charac. const and a string that contains a single char:
// // 'x' is not the same as "x". The former is an integer, used to produce the numeric val
// // of the letter x in the machine's character set. The latter is an array of chars that 
// // contains one char (the letter x) and a '\0'."
// {
//     // `str`: input string 
//     // `c`: character 
//     // Find first instance of `c` in `str` and return pointer to that first instance.

// // we're given the string and the numeric value of the character we're looking for

// // how do I approach this if:
//     printf("%d\n", c); // prints 101 in the test at bottom
//     printf("%c\n", *str); //prints H in the test at bottom
// //
// // 101 is the numerical 
// // If the numerical of *str[i] == numerical of c, return str[i] (the pointer).

// // i want to get the numeric value of str

//     // int i;

//     // for (i = 0; i < 10; i++) {
//     //     if (str[i] != 0) {
//     //         printf("%d\n", i);
//     //         printf("%c\n", str[i]);
//     //     }
//     // }


// }

// /////////////////////////////////////////////////////////////////