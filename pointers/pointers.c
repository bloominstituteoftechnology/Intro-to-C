#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.

    int x = 1, y = 2, z[10];
// int *ip;        /* ip is a pointer to an int */

// ip = &x;        /* ip now points to x */
// y = *ip;        /* y is now 1 */
// *ip = 0;        /* x is now 0 */
// ip = &z[0];     /* ip now points to z[0] */
// */
void swap(int* a, int* b) {

int aa = *a;
int bb = *b;

*a = bb;
*b = aa;

}

/*
    Given a character pointer s, returns the number of characters
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
*/
int string_length(char *s)
{
    int count = 0;
    while (s[count] != '\0') {
        // printf("%s\n", s);
        ++count;
    }
    return count;
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    *x = *y;
    int count = 0;
    while (y[count] != '\0') {
        ++count;
        x[count] = y[count];
    // printf("%s\n", x);
    // printf("%d\n", count);
    }
    x[count] = '\0';
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
*/
int string_compare(char *m, char *n)
{
    // printf("%c\n", *m); // h
    // printf("%c\n", *n + 1); // h

    int mlength = string_length(m);
    int nlength = string_length(n);
    // printf("%d\n", mlength); // 12

    int count = 0;

    for (int i = 0; i < mlength; i++ ) {
        for (int j = 0; j < nlength; j++) {
            if (m[i] > n[j]) {
                count--;
            } else if (m[i] < n[j]) {
                count++;
            }
        }
    }
    printf("%d\n", count);
    return count;
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
    printf("Length is %d\n", string_length(buffer));
    printf("Comparison is %d\n", string_compare(hello, world));

    return 0;
}
#endif
