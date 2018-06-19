#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int* a, int* b)
{
    // set up a place holder vairable
int placeholder = *a;
// set point of a to pointer of b
 *a = *b;
 //  set pointer of b to the placeholder variable
 *b = placeholder;
}

/*
    Given a character pointer s, returns the number of characters
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
    
    Do not just use the `strlen` function from the standard library.
*/
int string_length(char *s)
{
    // set i variable
    int i;
    // while s at i is not void increment i, after return i
    while(s[i])i++; return i;

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
    //set index variable
   int i =0;
   // iterate over the y pointer at i
for(; *(y+i); i++){
    // set x at i to y at i
    x[i] = y[i];
}
// add in null at the end of the x array
*(x+(i+1)) ='\0';

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
// while n or m have not reached the end of the string
while(*m != '\0'|| *n !='\0')
{
// if m is not equal to n
    if(*m!=*n)
    {
     // set a variable for  m - n
     int result = *m - *n;
     // return the variable.
    return  result; 
    }
    // else  increment n and m 
     n++;
     m++;
}
return 0;
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
