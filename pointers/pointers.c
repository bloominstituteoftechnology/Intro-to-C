#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int* a, int* b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(unsigned char *str, unsigned char c)
{
    unsigned char *i=str;
    while (*i != '\0'){
        if (*i == c){
            return i;
        }
        i++;
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
    while (*y != '\0'){
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
    while(*m !='\0' || *n != '\0'){
        int comparison = *m-*n;
        if (comparison != 0){
            return comparison;
        }
        m++;
        n++;
    }
    return *m-*n;    
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
    int found;
    char *needle_temp;
    char *haystack_temp;
    while (*haystack != '\0'){
        if (*haystack == *needle){
            haystack_temp = haystack;
            needle_temp = needle;
            found = 0;
            while (*needle_temp != '\0' && *haystack_temp == *needle_temp){
                haystack_temp++;
                needle_temp++;
                if (*needle_temp == '\0'){
                    found = 1;
                }
            }
            if (found == 1){                
                return haystack;
            }
        }
        haystack++;
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

    // Test case for string_compare:
    //
    // char *hello_world = "hello world";
    // char *goodbye = "goodbye";
    // printf("Compare 'hello world' and 'goodbye': %d\n", string_compare(hello_world, goodbye));

    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    // Test case for find_string:
    // 
    // char *found_str = find_string(hello_world, "ld");
    // printf("Found string: %s\n", found_str);

    return 0;
}
#endif
