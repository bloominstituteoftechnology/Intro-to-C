#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int* a, int* b)
{  
    int holder = *a;
    *a = *b;
    *b = holder; 
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
    int i; // --> create index
    char holder = c; // --> hold the CHAR of what we're looking for
    // --> the byte of 'e' is 101 in int form

    for(i = 0; str[i] != 0; i++) // --> as long as the 0'th index of the given string is not null
    { 
    printf("str[i] is: %c\n", str[i]); // --> H, e, l, l, o

        if(holder == str[i]) // --> check for comparison of letters
        {
        return &str[i]; // --> return pointer of first instance
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
    printf("char *y is: %c\n", *y);
    // while there is a valid char *y given...
    // --> *x = *y;
    // --> since there is more than one char we increment
    while(*y)
    {    
        *x = *y; // --> copy y to x 
        x++; // --> increment to next index of buffer array  
        y++; // --> move to next letter in str       
    }
    *x = '\0'; // --> need to add null char at end of string    
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
  int x; // --> initialize first counter
  for (x = 0; m[x] != 0; x++){ // --> check if the first string is valid

    if (m[x] == n[x]) 
    { // --> if they match, it's not equal to anything
      continue;
    }

    if (m[x] > n[x]) 
    { // --> base case #1
      return 1;
    }

    if (m[x] < n[x]) 
    { // --> base case #2
      return -1;
    }

  } // --> For loop brace

  int i, j;
  int count1 = 0;
  int count2 = 0;

  for(i = 0; m[i]; i++){
    count1++;
  }

  for(j = 0; n[j]; j++){
    count2++;
  }

  if(count1 != count2){
    return -1;
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
