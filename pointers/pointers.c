#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int *a, int *b)
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
    int i = 0;
    while (*(str + i) != "\0")
    {
        char tmp = *(str + i);
        if (tmp == c)
        {
            return *(str + i);
        }

        i++;
    }
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
    
    Do not just use the `strcpy` function from the standard library.
*/
int string_length(char s[])
{
    int length = 0;
    //int array_size = sizeof(s) / sizeof(s[0]);
    int i = 0;
    // printf("Char size: %d\n", sizeof(s[0]));
    // printf("String (array) size: %d\n", sizeof(s));
    while (*(s + i) != '\0')
    {
        length = length + 1;
        i++;
    }

    return length;
}

void string_copy(char *x, char *y)
{

    int i = 0;
    for (int i = 0; i < string_length(y) + 1; i++)
    {
        x[i] = y[i];
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
    
    Do not just use the `strcmp` function from the standard library.
*/
int string_compare(char *m, char *n)
{
    // printf("%s\n", m);
    // printf("%s\n", n);
    int i = 0;
    int j = 0;
    int length = 0;
    int length_m = string_length(m);
    int length_n = string_length(n);
    if (length_m >= length_n)
    {
        length = length_m;
    }
    else
        length = length_n;
    while (i < length)
    {
        char tmp = m[i];
        // printf("%c", tmp);
        // printf("%c", n[j]);
        // printf("\n");
        if (tmp != n[j])
        {
            return m[i] - n[j];
        }

        i++;
        j++;
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
}

#ifndef TESTING
int main(void)
{
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);

    char *hello = "Hello";
    char *world = "World";
    // char *hello = "Firetruck";
    // char *world = "Firetrucks";
    char buffer[1024];

    string_copy(buffer, hello);

    printf("Buffer is %s\n", buffer);
    printf("Comparison is %d\n", string_compare(hello, world));
    //printf("Comparison is %d\n", string_compare('hello world', 'hiya'));
    // char *found_char = find_char(hello, 'e');
    // char *found_string = find_string(world, "or");

    // printf("Found char: %s\n", found_char);
    // printf("Found string: %s\n", found_string);

    return 0;
}
#endif
