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
    int b_prev_value = *b;
    *b = *a;
    *a = b_prev_value;
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    char *p = str;

    while (*p != '\0') {
        if (*p == c) {
            return p;
        }
        p++;
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
    int len = strlen(y);
    
    for (int i = 0; i < len; i++) {
        x[i] = y[i];
    }
    x[len] = '\0';
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
    //hello, world  || hiya
    int len;
    if (strlen(m) > strlen(n)) {
        len = strlen(m);
    }
    else {
        len = strlen(n);
    }
    for (int i = 0; i < len; i++) {
        if (m[i] < n[i]) {
            return -1;
        }
        if (m[i] > n[i]) {
            return 1;
        }
    }
    return 0;
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
    unsigned int counter = 0;
    char *hay_copy = haystack;
    while (*hay_copy != '\0') {
    // printf("%c, %c\n", *hay_copy, *needle);
        
        if (*hay_copy == *needle) {
            for(unsigned int i = 0; i < strlen(needle); i++) {
                // printf("%c", *(hay_copy+i));
                if (*(hay_copy + i) != needle[i]) {
                    break;
                }
                counter++;
            }
            // printf("%d", counter);
            if(counter == strlen(needle)) {
                return hay_copy;
            }
        }
        hay_copy++;
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
    printf("Comparison is %d\n", string_compare("hello, world", "hiya"));

    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
