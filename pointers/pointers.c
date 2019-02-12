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
    int tmp = *a;
    *a = *b;
    *b = tmp;
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
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        int num_letter = str[i];

        if (num_letter == c)
        {
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
    int i = 0;
    while (y[i] != '\0')
    {
        x[i] = y[i];
        i++;
    }
    x[i] = '\0';
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
    int m_len = strlen(m);
    int n_len = strlen(n);
    int highest = 0;

    if (m_len > n_len)
    {
        highest = m_len;
    }
    else
    {
        highest = n_len;
    }

    for (int i = 0; i < highest; i++) 
    {
        int m_char = m[i] - '0';
        int n_char = n[i] - '0';

        if (m_char < n_char)
        {
            return -1;
        }
        else if (m_char > n_char)
        {
            return 1;
        }
        else
        {
            continue;
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
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);
    int counter = strlen(haystack);

    for (int i = 0; i < haystack_len; i++)
    {
        if (haystack[i] == needle[0] && counter >= needle_len)
        {
            return &haystack[i];
        }
        counter--;
    }
    return NULL;
}

// LambdaSchool
// Lambda

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
