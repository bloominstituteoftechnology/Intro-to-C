#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int* a, int* b)
{
  int holdb =*b;
  int holda = *a;
  
  *b = holda;
  *a = holdb;
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
  char *pointer;
  
  for(int i = 0; str[i] != '\0'; i++){
    if(str[i] == c){
      pointer = &str[i];
    }
  }
  
  
  return pointer; 
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
  int i; 
  for(i = 0; y[i] != '\0'; i++){
    
    x[i] = y[i];
  }

  i++;
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
  int i; 
  for(i = 0; m[i] != '\0' || n[i] != '\0'; i++){
    //while we have not reached the end of a string keep going. 
    if(m[i] < n[i]){
      return 22;
    } else if (m[i] > n[i]){
      return -22;
    }
  }
  //check for if both strings matched up until one ended before other
  if (m[i] == '\0' && n[i] != '\0'){
    return -22; // m would be greater 
  } else if (m[i] != '\0' && n[i] == '\0'){
    return 22; // m would be less
  } else {
    //ended without returning and both are '\0' strings are equal 
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
//https://repl.it/@codejoncode/Pointers-Intro-to-C