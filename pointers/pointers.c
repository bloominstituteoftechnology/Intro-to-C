#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int* a, int* b)
{
 if (a != b)
  {
    *a += *b;
    *b = *a - *b;
    *a -= *b; 
  }   
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
    //* for dereference for initializing pointer
    char *v = 0;
    while(*str != '\0')
    {
        // * gives us the value, dereferences from the address
        if(*str == c)
        {
            v = str;
        }
        str++;       
    }
    return v;
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
    
    Do not just use the `strcpy` function from the standard library.
*/

//void first, returns nothing, changes are global
void string_copy(char *x, char *y)
{
   int counter = 0;
   for(; y[counter] != '\0'; counter++)
   // below only allowed because of line 55 initialization 
   // for(counter = 0; y[counter] != '\0'; counter++)
   {
       x[counter] = y[counter];
   }
   x[counter] = '\0';
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
    // typedef int bool;
    // #define true 1;
    // #define false -1;

    int count = 0;
    for(; m[count] != '\0' || n[count] != '\0'; count++)
    {
        if(m[count] < n[count])
        {
            return -1;
        }
        else if (m[count] > n[count])
        {
            return 1;
        }
    }
    // count is saved because it's initialized outside of the for loop on line 85 and we use those values below
    if(m[count] == '\0' && n[count] != '\0')
    {
        return 1;
    }
    else if (n[count] == '\0' && m[count] != '\0')
    {
        return -1;
    }
    else 
    {
        return 0;
    }

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
    //counter for haystack, count for needle
    int counter = 0, count = 0;
    char *result = NULL;

    while(haystack[counter])
    {
        if(haystack[counter] != needle[count])
        {
            counter++;
            count = 0;
        }
        else 
        {
            result = &haystack[counter];
            while(needle[count] != '\0')
            {
                counter++;
                count++;
                if(needle[count] == '\0')
                {
                    return result;
                }
                if(haystack[counter] != needle[count])
                {
                    count = 0;
                    break;
                }
            }
            if(needle[count] == '\0')
            {
                return result;
            }
        }
    }
    return NULL;
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
