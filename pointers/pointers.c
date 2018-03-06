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
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("The value of a is %d\n", *a);
    printf("The value of b is %d\n", *b);
}

/*
    Given a character pointer s, returns the number of characters
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
*/
int string_length(char *s)
{
    // return strlen(s); Works with library but wanted to try it this way
    int length = 0;

    while(*s != '\0')
    {
        length++;
        s++;
    }

    return length;
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    printf("Called string_copy\n");
    while(*y != '\0')
    {
        *x = *y;
        x++;
        y++;
    }
    *x = '\0';
    printf("Finished string copy\n");
}

/* 
    Compares the character strings m and n and returns negative,
    0, or positive if n is lexicographically less than, equal to,
    or greater than n. To calculate lexicographic difference, find
    the difference between the first characters in m and n that differ.
    
    For example, given matching strings, this function should 
    return 0. Given strings m = "hello world" and n = "goodbye",
    this function should return a negative value. Given strings
    m = "aardvark" and n = "zebra", should return a positive
    value.
*/
int string_compare(char *m, char *n)
{
    printf("called string_compare\n");

    for (; *m == *n; m++, n++)
    {
        if(*m == '\0')
        {
            return 0;
        }
    }
    return *n - *m;
}

#ifndef TESTING
int main(void)
{
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);

    char *test = "hello";
    int testLength = string_length(test);
    printf("The length of our test is %d\n", testLength);

    char *swap1 = "Ferrari";
    char testBuffer[1024];

    printf("we start with %s in swap1 and %s in nullString\n", swap1, testBuffer);

    string_copy(swap1, testBuffer);

    printf("After running string_copy we have %s in swap1 and %s in nullString\n", swap1, testBuffer);

    char *animal1 = "aardvark";
    char *animal2 = "zebra";

    int testResult = string_compare(animal1, animal2);

    printf("String compare returned %d", testResult);

    // char *hello = "Hello";
    // char *world = "World";
    // char buffer[1024];

    // string_copy(buffer, hello);

    // printf("Buffer is %s\n", buffer);
    // printf("Length is %d\n", string_length(buffer));
    // printf("Comparison is %d\n", string_compare(hello, world));

    return 0;
}
#endif