#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tempB = *b;
    int tempA = *a; 
    *a = tempB;
    *b = tempA;
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/

int string_length(char s[])
{
    int count = 0;
    for (int i = 0; ; i++){
        if(s[i] == '\0'){
            return count;
        }
        count += 1;
    };
}


char *find_char(char *str, int c)
{   
    printf("\n%s, %c\n\n", str, c);
    printf("start\n");
    // int len = string_length(str);
    printf("len\n");
    char *new = NULL;
    for(int i = 0; str[i]!= '\0'; i++){
        printf("loop %i -- str%d\n", i, str[i]);
        if(str[i] == c){
            // printf("%p this is the memory slot in ram\n", str);
            new = &str[i];//returns the address not the value
            // printf("%p this is the memory slot in ram now\n", str);
            printf("new -> %s\n\n",  new);
        };
    };
    return new;
}



/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
    
    Do not just use the `strcpy` function from the standard library.
*/
void string_copy(char *x, char *y)//x is a pointer to a first character it is not a complete string it just goes until it it hits that null value
{
    printf("*x start (value) => %c\n", *x);
    printf("x start (pointer) => %p\n", x);
    printf("*y start (value) => %c\n", *y);
    printf("y start (pointer) => %p\n\n", y);

    // int *somecharacter; //pointer to a char
    // printf("*somecharacter => %c\n", *somecharacter);
    // somecharacter = &y; //somecharacter now points to y
    // printf("somecharacter => %s\n", somecharacter);
    // *x = *y; //x should now be the value of somecharacter
   
    // *(y+1)

    int i;
    for (i=0; y[i] != '\0'; i++){
        x[i] = y[i];
    } 
    x[i] = '\0';

    // printf("x end => %s\n", x);
    // printf("*x end => %d\n", *x);
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

    //loop through and compare the nth index of each until there is a difference.  
    //if the value of n is closer to a than m return 1 // m=aaaa
    //if the value of m is closer to a than n return -1 // n=aaaab
    //if the value of each is the same throughout return 0
    int lenM = string_length(m);
    int lenN = string_length(n);

    int biggerLen;

    if(lenM > lenN){
        biggerLen = lenM;
    } else {
        biggerLen = lenN;
    }

    for ( int i = 0; i < biggerLen ; i++){
        if(m[i] != n[i]){
            return m[i] - n[i];
        };
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
    int lenH = string_length(haystack);
    int lenN = string_length(needle);

    if(lenH < lenN){
        return NULL;
    };

    for (int i = 0; haystack[i] != '\0'; i++){
        printf("haystack i = %d /", i);
        if (haystack[i] == needle[0]){
            printf(" haystack[i] = %c /", haystack[i]);
            printf(" needle[0] = %c\n", needle[0]);
            for (int k = 0; k < lenN ; k++){
                printf("needle[k] = %c\n", needle[k]);
                if (needle[k] != haystack[i +k]){
                    break;
                }
                if (k+1 == lenN){
                    printf("found needle\n");
                    return &haystack[i];
                }
            }
        } else {
            printf(" they are not equal");
            printf(" haystack[i] = %c /", haystack[i]);
            printf(" needle[0] = %c\n", needle[0]);
        }
    }
    printf(" no needle found\n\n");
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

    char *found = "LambdaSchool";
    find_char(found, "bdaSchool");

    return 0;

}
#endif
