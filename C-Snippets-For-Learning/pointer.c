#include <stdio.h>

int main(void)
{
    // declare a pointer to the string "I'm a string!"
    char *str = "I'm a string!";
    // print out the value of the actual pointer, or the address of the string
    printf("Address of string(value of pointer): %p\n", str);
    // print out the value of the string
    printf("Actual value of string: %s\n", str);
}

