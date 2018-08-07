#include <stdio.h>
//define funcs
void swap(int *a, int *b);
int string_length(char *s);
void string_copy(char *x, char *y);
int string_compare(char *m, char *n);


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
    printf("Length is %d\n", string_length(buffer));
    printf("Comparison is %d\n", string_compare(hello, world));

    return 0;
}
#endif

void swap(int *a, int *b){
    int temp = *a; // temp points to a
    *a = *b; // a points to b
    *b = temp; // b points to old a;

}


int string_length(char *s){
    int len = 0;
    while (*s != '\0'){
        len ++;
        s++;
    }
    return len;
}

void string_copy(char *x, char *y){
    while(*y != '\0'){
        *x = *y;
        x++;
        y++;
    }
    *x = '\0';  // x points to new null
}

/* 
    Compares the character strings m and n and returns negative,
    0, or positive if n is lexicographically less than, equal to,
    or greater than n. To calculate lexicographic difference (ASCII code difference), find
    the difference between the first characters in m and n that differ.
    
    For example, given matching strings, this function should 
    return 0. Given strings m = "hello world" and n = "goodbye",
    this function should return a positive value. Given strings
    m = "aardvark" and n = "zebra", should return a negative
    value.
    
    Do not just use the `strcmp` function from the standard library.
*/
int string_compare(char *m, char *n){
    int i = 0;
    while(m[i] !='\0'){
        if(n[i] == '\0'){
            return 1;
        }
        else if(m[i] > n[i]){
            return 1;
        }
        else if(m[i] < n[i]){
            return -1;
        }
        i++;
    }
    if (n[i] == '\0'){
        return 0;
    }
    else {
        return -1;
    }

  

    
    
}



