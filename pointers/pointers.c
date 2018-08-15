#include <stdio.h>



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

}



/*

    Given a character pointer s, returns the number of characters

    it is pointing to. Think about how pointer arithmetic can 

    help you with this.

    

    Do not just use the `strlen` function from the standard library.

*/

int string_length(char *s)

{

    int string = 0;

    while (*s != '\0')

    {

        string++;

        s++;

    }

    return string;

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

    /* While the pointer for y is not equal to the null character,

    assign the pointer for x to the pointer for y.

    Increment the pointer for y to the next element in the array.

    Increment the pointer for x to the next element in the array. */



    while (*y != '\0') {

        *x = *y;

        y++;

        x++;

    }

    /* set the pointer for x, which should be at the end now, to null character */

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

    /* while dereferenced m (so the value of m) equals dereferenced n

    if the value of m is a null character, return 0 -

    else, increment the pointer for m and the pointer for n

    when the value of m is no longer equal to the value of n,

    return the value of m minus the value of n */

    while (*m == *n)

    {

       if (*m == '\0')

       {

           return 0;

       }

       m++;

       n++;

    }

    return *m - *n;

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