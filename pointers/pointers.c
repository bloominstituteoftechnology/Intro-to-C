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
    // a is a pointer to an int.
    // b is a pointer to an int.
    int temp = *a; //temp is now a's value
    *a = *b;
    *b = temp;

}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
    Return NULL if the character is not found.
*/

// signed char will be an 8-bit two's complement number ranging from  -128 to 127, 
// unsigned char will be an 8-bit unsigned integer (0 to 255). 
char *find_char(char *str, int c)
{
    // while (*str != '\0') { // iterate along y char-by-char until null terminator
    //     if(*str == c) {
    //         return str;
    //     }
    //     str++;
    // }
    // return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if(str[i] == c) {
            return &str[i];
        }
    }
    return NULL;
}



/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
    
    Do not just use the `strcpy` function from the standard library.
*/
void string_copy(char *x, char *y)
{
    while (*y != '\0') { // iterate along y char-by-char until null terminator
        *x = *y;          // set the corresponding x to that char 
        y++;            // increase y
        x++;             // increase x
   }
   *x = '\0';    // since iteration was up to null terminator add it to the end
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
        //
    while (*m != '\0') { // iterate along y char-by-char until null terminator
        if (*m == *n) { // if chars match cont. to iterate 
            n++;    
            m++;        
        } else {  // if no match, return positive or negative
            return (*m>*n) ? 1: -1;
        }
   }
   // if both *m and *n are null terminator, return 0 else pos or neg
   return (*m == *n) ? 0: (*m>*n) ? 1: -1; 
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
    int h = strlen(haystack);
    int n = strlen(needle);
    if (n > h) {
        return NULL;
    }
    int j = 0;
    int match = 0;
    char *first;
    for(int i=0; i<h && j < n; i++) {
        if(needle[j] == haystack[i]) {
            if (!match) {
                first = &haystack[i];
            }
            match = 1;
            j++;
            if(needle[j] == '\0') {
                return first;
            }
        }
        
    }
    return NULL;
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
    printf("Comparison is %d\n", string_compare(hello, world));

    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
