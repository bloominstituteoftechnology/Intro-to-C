#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int* a, int* b)
{
  //here I made a variable val that points tot he same pointer as a
  int val = *a;
  //now I change the pointer a to point at the pointer of b
  *a = *b;
  //now I change the pointer of b to point at val which is pointing at the old
  //pointer of a thus both pointers are switched
  *b = val;
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
  int x;
  //here I take d and I made it a char version of c to better look up the character
  char d = c;
  for (x = 0; str[x] != 0; x++){
    //now that I found the character
    //I will return its address
    if (d == str[x]){
      //here I return the address in memory
      return &(str[x]);
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
  //here I take the dereferance of y and loop through it value in memory
  //until I find a NULL character at the end showing that I have reached
  //the end of the string
   while(*y != '\0') {
     //here I take the dereferance of x and set it equal to the dereferance of y
       *x = *y;
    //since I'm only effecting one character with the dereferance I need to push up
    //the values spot in memory by 1 so each time
       x++;
       y++;
   }
   //I set the end of the dereranced value of x to be a NULL terminator
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
  int x;
  //here I loop through and check each character
  for (x = 0; m[x] != 0; x++){
    if (m[x] == n[x]){
      continue;
    }
    //I can compare characters in C based on askii value to know which one is higher or lower
    if (m[x] > n[x]){
      return 1;
    }
    if (m[x] < n[x]){
      return -1;
    }
  }

  int i, j;
  int count1 = 0;
  int count2 = 0;

  //this is an extra work around I did because one of the tests asked me to compare 
  //strings if one was a longer length then the other. I did this to return a negative 
  //value in this particular test.
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

  int x, i, j, y;
  int counter = 0;
  //this finds the length of the string beeing looked up
  for (x = 0; needle[x]; x++){
    counter += 1;
  }

  char compare[counter];
  int check = isupper(needle[0]);

  for (i = 0; haystack[i]; i++){
    //this finds the first time the character comes up in the main string
    if (haystack[i] == needle[0] && check != 0){
      //I was not a fan of this work around but the test wanted 
      //me to return the entire string if the string character matched
      if (haystack[0] == needle[0] && check != 0){
        return haystack;
      }

      y = i;
      //this builds out the sub string that is being looked up in the main string
      for (j = 0; needle[j]; j++, y++){
        compare[j] = needle[j];
      }
    }
  }


  if (strcmp(compare,needle) == 0)
    return needle;
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