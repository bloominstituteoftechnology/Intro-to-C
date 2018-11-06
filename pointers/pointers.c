#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int* a, int* b)
{
    //temp is holding the value that a points to
    int temp = *a;
    //set a to point to the value that b is pointing to
    *a = *b;
    //set b to point to the value that temp is holding
    *b = temp;
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
    int s_len;
    int i;
    s_len = strlen(str);
    for (i = 0; i < s_len; i++) {
        if ((char) c == str[i]) {
            return (const char*) &str[i];
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
    //walk along y until we reach the end of the string
    while (*y != '\0') {
        //copy the current char we're at to x
        *x = *y;
        //increment x and y pointers
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
    //iterate over both char pointers
    while(*m == *n) {
        //check to see if we've reached the end of one of the strings
        if (*m == '\0') {
        return 0;
    }
    //increment both pointers
    m++;
    n++;
    }
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
    int i = 0, j = 0;
    while ((*(haystack + j) != '\0')&&(*(needle + i) != '\0')) {
        if (*(needle + i) != *(haystack + j)) {
            j++;
            i = 0;
        }
        else {
            i++;
            j++;
        }
    }
    if (*(needle + i) == '\0')
        return 1;
    else
        return -1;
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
