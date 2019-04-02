#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    printf("test\n");
    char *p = y;
    int count = 0;
    int con_count = 0;
    char* str = NULL;
     
    for(count=0; count < strlen(y); count = count + 1){
      printf("printing string y: %c\n", *(p + count));
      x[count] = *(p + count);
      if (strlen(y) - 1 == count){
        x[count + 1] = '\0';
      }
    }
    printf("string x: %s\n", x);

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
    printf("test\n");
    return 'l';
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
    printf("test\n");
    return 'l';
}

#ifndef TESTING
int main(void)
{
    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("BUFFER: %s\n", buffer); // Prints "Hello!"
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    // printf("Found char: %s\n", found_char);
    // printf("Found string: %s\n", found_string);

    return 0;
}
#endif
