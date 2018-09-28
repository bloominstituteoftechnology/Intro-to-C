#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int* a, int* b)
{
    // printf("%d\n", a);
    // printf("%d\n", *a);
    // printf("%d\n", b);
    // printf("%d\n", *b);
    int x = *a;
    int y = *b;
    *a = y;
    *b = x;
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c) {
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == c) {
            return str + i;
        }
    }
}
// {
//     int count = 0;
//     char search = '\0';
//     while (search != c || search == 0) {
//         if (str[count] == c) {
//             search = c;
//             return count;
//         }
//         else if (str[count] == '\0') {
//             search = 0;
//         }
//     // printf('%c\n', str[count]);
//     return str+count;
//     }
// }

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
    
    Do not just use the `strcpy` function from the standard library.
*/
void string_copy(char *x, char *y)
{
    // y is an address
    // *y is a character
    while(*y != '\0') {
        *x = *y;
        x++;
        y++;
    }
    *x = '\0';
}

/* 
    Compares the character strings m and n and returns negative,
    0, or positive if n is lexicographically less than, equal to,
    or greater than n. To calculate lexicographic difference, find
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
    //dereference to compare characters
    while ( *m == *n) {
        if ( *m =='\0') {
            return 0;
        }
        m++;
        n++;
    }
    // if (*m > *n) {
    //     return 1;
    // }
    // else {
    //     return -1;
    // }
    return *m - *n;
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
    //loop through haystack
    for ( int h = 0; h < strlen(haystack); h++) {
        //char if need is here
        if (haystack[h] == needle[0]) {
            //save poisition as a pointer
            char *first = haystack + h;
            int n = 1;
            h++;
            //find rest of needle
            while(haystack[h] == needle[n]) {
                h++;
                n++;
                if( needle[n] == '\0') {
                    return first;
                }
            }
        }
    }
    return NULL;
}

// #ifndef TESTING
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
    printf("Comparison is %d\n", string_compare(hello, world));

    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
// #endif
