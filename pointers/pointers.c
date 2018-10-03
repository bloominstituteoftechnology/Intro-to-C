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
  // printf("a was %d\n", a);
  // printf("b was %d\n", b);

  int temp = *a;
  *a = *b;
  *b = temp;
  return;
  // printf("a is now %d\n", a);
  // printf("b is now %d\n", b);
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
  while (*str)
  {
    if (*str == c)
      return str;
    str++;
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
  int ct = 0;
  for(int i = 0; y[i] != '\0'; i++){
    x[i] = y[i];
    ct++;
  }
  x[ct] = '\0';
  return;
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
if (m == n) {
  return 0;
}

for(int i = 0; m[i] != '\0'; i++) {
  for (int i = 0; n[i] != '\0'; i++) {
    if (m[i] == n[i]) {
      printf("same %c, %c\n", m[i], n[i]);
      continue;
    }
    else if (m[i] < n[i]) {
      printf("m<n %c, %c\n", m[i], n[i]);
      return -1;
    } 
    else if (m[i] > n[i]) {
      printf("m>n %c, %c\n", m[i], n[i]);
      return 1;
    } else {
      continue;
    }
  }
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
 char *h = haystack;
 char *n = needle;
 size_t n_length = strlen(needle);
 size_t h_length = strlen(haystack);

 char *sub = find_char(h, n[0]); //checks to see if first character is present.
 printf("sub = %s\n", sub);

 if (n_length == 0 || h_length == 0 || n_length > h_length) {
   return NULL;
 }
if (sub) {
  for (int i = 0; n[i] != '\0'; i++){
    if(sub[i] != n[i]) {
      return NULL;
    }
    }
    return sub;
  }
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

  find_char(hello, 'e');

  printf("Buffer is %s\n", buffer);
  printf("Comparison is %d\n", string_compare(hello, world));

  char *aardvark = "aardvark";
  char *zebra = "zebra";
  string_compare(aardvark, zebra);

  char *found_char = find_char(hello, 'e');
  char *found_string = find_string(world, "or");

  printf("Found char: %s\n", found_char);
  printf("Found string: %s\n", found_string);

  return 0;
}
#endif
