#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/

// #include <stdio.h>

// int main(void)
// {
// 	int x = 0;   // Set x to 0

// 	int *p = &x; // Set p to point to x, set to address of x

// 	*p = 3490;   // Set the thing that p points to to 3490

// 	printf("x is %d\n", x);  // 3490
// 	printf("x is %d\n", *p); // 3490 
// printf("p is %d\n", &p);
// printf("x is %d\n", &x);

// 	return 0;
// }


void swap(int* a, int* b)
{
    
    // int a;
    // int b;
    printf("before --- a: %d b: %d\n", *a, *b);
    int c = *a;
    *a = *b;
    *b = c;
    /*
    We got:
    a = 10;
    b = 20;
    We want:
    a = 20;
    b = 10;

    i
    *a = *b;
    // the value of a now is 20 
    *b = *a;
    // the value of b is still 20
    */

    printf("after --- a is %d\n", *a);
    printf("after --- b is %d\n", *b);
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
    for (int i = 0; i < strlen(str); i++) {

        if(str[i] == c)  {
            // printf("The character %c was found.\n", str);
            return &str[i]; 
        }
    }
    return NULL;
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary heres Also, make sure x points to a null character at its 
    end to terminate it properly. 
    
    Do not just ;use the `strcpy` function from the standard library.
*/
void string_copy(char *x, char *y)
{
    // printf(x, y);
    for (int i = 0; i < strlen(y); i++){
        x[i] = y[i];
        printf(x);
    }
    x[strlen(x) - 1] = '\0';
    printf("STRINGS x: %s y: %s\n", x, y);
    /*
    char str[] = "ass";
    str[0] == 'a'
    str[1] == 's'
    str[2] == 's'
    str[3] == '\0'
    str[2] = 'l'
    str == "asl"
    */
    return x;
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
 /*
    So try to solve the simplest problem. What should this function return?
    Ex. string_compare('a', 'd') < 0 : That is, the output of this function call should be less than 0
        string_compare('s', 's') == 0
        string_compare("hello world", "goodbye") > 0 : output of this should be more than 0
        string_compare("firetruck", "firetrucks") < 0 : output of this function should be less than 0
    ---
    Remember, you can "subtract" characters. Like 'd' > 'a', so 'a' - 'd' < 0
    like 'b' - 'a' == 1
    You wanna zoom? 
    
 */
// 

    int i = 0;
    printf("m: %c n: %c\n", *m, *n);
    if (*m - *n != 0) {
        return *m - *n;
    } else if (*m == '\0' || *n == '\0') {
        return *m - *n;
    }else {
        return string_compare(m + 1, n + 1);
    }
    return *m - *n;

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
    /*
    Think about this situation:
    haystack: 'hello world'
    needle: 'word'

    So in the above example, `find_string('hello world', 'word');` should
    return NULL, because 'word' isn't in 'hello world' exactly.

    I should be asking, what would your function return in the above situation?    
        a pointer R: yep!        


    What does it mean the first instance? the first letter of the word...?
haystack: wo'wrordy word words'
    needle: 'word'
    It should return a pointer TO first instance of 'word', which would be the
    the very first 'word' in 'wordy'. got it, so the whole word
    wordy contains word R: yes and it's athe wfirst instance in the string to have it

    So the idea is that if the first character matches between both the haystack and the 
    needle, you should check the rest of the letters in haystack and see if they match with
    the needle. If it does, you found your match. If not, drop it and move on.

    What was your code before? That was good. It just didn't address that one case. We could 
    just modify it.
    
    the direction I was going wasn't making sense to me any more, so I took it out R: Got it
    What's the direction you want to go toward to now? Explain/write it out before you dive
    into the code
    */
    
    
    // if the value is equal to the first pointer of needle
    
    // Loop through haystack
    printf("this is happenin\n");
    // printf("strlen haystack: %d\n", strlen(haystack));
    for (int i = 0; i < strlen(haystack); i++){
       
        if(needle[0] == haystack[i]){
            int j = 0;
            while(needle[j] != '\0') {
                if (needle[j] != haystack[i + j]) {
                    break;
                }else {
                    j = j + 1; // j++;
                }
            }
            if (needle[j] == '\0') {
                printf("find_string RETURN VALUE: %s\n", haystack);
                return &haystack[i];
            }   
  
        }
    }
    return NULL;
    // return haystack;
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


    printf("Buffer is %s\n", buffer);
    printf("Comparison is %d\n", string_compare(hello, world));

    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    string_copy(buffer, hello);
    return 0;
}
#endif
