#include <stdio.h>
#include <stdbool.h>


void substring(char s[], char sub[], int p, int l);

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
// copies y into x
void string_copy(char *x, char *y)
{
  char * current = y;
  int pos = 0;
  while (*(y+pos) != '\0' && pos < 100) {
    printf("current: %p %s ", current, current);
    printf("X: %p, Y: %p", x+pos, y+pos);
    *(x+pos) = *(y+pos);
    printf("  X: %c, Y: %c\n", *(x+pos), *(y+pos));
    current = y+pos;
    pos++;
  }
  // x[pos] = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, char c)
{
  int count = 0;
  
  while(*(str+count) != '\0') {
    if (*(str+count) == c) {
      //char ** found_char = &(str+count);
      //return *found_char;
      char * found_char = malloc(sizeof(char));
      *found_char = *(str+count);
      return found_char;
    }
    count++;
  }

  return NULL;
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
  int count = 0;
  char * substr;

  // printf("haystack contains: %s, needle contains: %s \n", haystack, needle);

  while(*(haystack+count) != '\0') {
    // printf("%c \n", *(haystack+count-1));
    // substr = malloc(sizeof(char) * strlen(needle)+1);
    substr = calloc(strlen(needle)+1, sizeof(char));

    substring(haystack, substr, count, strlen(needle));

    // printf("substr: %s \n", substr);

    // loop through needle to compare charaters?
    bool matches = true;
    for (int i = 0; i < strlen(needle); i++) {
      // printf("i: %d \n", i);
      // printf("substr: %s, needle: %s\n", substr, needle);
      // printf("substr: %c, needle: %c\n", *(substr+i), *(needle+i));
    
      if (*(substr+i) != *(needle+i)) {
        matches = false;
        //char ** found_char = &(str+count);
        //return *found_char;
        // printf("\nnope\n");
        //break;
      }
    }
    
    // check if matches is true
    if (matches) {
        // printf("We have found %s", *substr);
        return substr;
    }

    free(substr);
    count++;
  }
  //return needle;
  return NULL;
}


#ifndef TESTING
int main(void)
{
    int num = 10;
    //printf((int)((ceil(log10(num))+1)*sizeof(char)));
    char *hello = "Hello\0";
    char *world = "World\0";

    // char buff[10];
    // string_copy(buff, "hello\0");
    // printf("buff contains: %s\n", buff);

    char *found_char = find_char(hello, 'e');
    //string_copy(found_char, 'e');
    char *or = "or";
    char *found_string = find_string(world, or);
    printf("\n");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif


//C substring function definition
void substring(char s[], char sub[], int p, int l) {
   int c = 0;

   while (c < l) {
      sub[c] = s[p+c-1];
      c++;
   }
   sub[c] = '\0';

  //  printf("sub: %s \n", sub);
}
