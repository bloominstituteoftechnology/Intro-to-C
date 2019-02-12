#include <stdio.h>
#include <string.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
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
    char *temp = NULL;
    printf("this should be the string: %s \n", str);
    for (int i = 0; i < strlen(str); i++)
    {
        printf("this is the letter we are at: %c \n", str[i]);
        printf("this is the letter we are at's value: %d \n", str[i]);
        printf("this is the value we are looking for: %d \n", c);
        if (str[i] == c)
        {
            temp = &str[i];
            printf("we are returning this: %s \n", temp);
            return temp;
        }
    }
    printf("we are returning this: %s \n", temp);
    return temp;
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
    int x_counter = 0;
    for (int i = 0; i <= strlen(y); i++)
    {
        x[x_counter] = y[i];
        x_counter++;
        if (i == strlen(y))
        {
            x[x_counter + 1] = '\0';
        }
    }
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
    
    if n>m return positive
    if n<m return negative
    if n==m return 0

    Do not just use the `strcmp` function from the standard library.
*/
int string_compare(char *m, char *n)
{
    int length = 0;
    int counter = 0;
    // printf("this is a string maybe?: %s \n", m);
    // printf("this is a string maybe?: %s \n", n);

    if (strlen(m) > strlen(n))
    {
        length = strlen(m);
    }
    else if (strlen(m) < strlen(n))
    {
        length = strlen(n);
    }
    else
    {
        length = strlen(n);
    }
    for (int i = 0; i < length; i++)
    {
        if (n[i] > m[i])
        {
            // printf("this should be a number?: %d \n", *m);
            // printf("this should be a number?: %d \n", *n);
            // printf("Im in a positive \n");
            return m[i] - n[i];
        }
        else if (n[i] < m[i])
        {
            // printf("this should be a number?: %d \n", *m);
            // printf("this should be a number?: %d \n", *n);
            return m[i] - n[i];
        }
    }
    // printf("this is counter being returned: %d \n", counter);
    return counter;
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
    printf("we are now finding a string");
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
