#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
// Note that the asterisk (pointer declaration) can be placed on 
// either side of either the `int` OR the variable.
// Below, where we see `*a` w/o `int` is called "dereferencing"
void swap(int* a, int* b)
{
    int x = *a; // Here the asterisk gets us the VALUE that the memory address that `a` points to
    *a = *b;
    *b = x;

    // // Sean's Solution:
    // int temp = *a;
    // *a = *b;
    // *b = temp;

} 

/*
    Given a character pointer s, returns the number of characters
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
*/
int string_length(char *s)
{
    int i = 0;
    while (*(s+i) != '\0') {
        // printf("%s", *s);
        i++;
    }
return i;
}

// // Sean's Solution:
// int string_length(*char s) {
//     int length = 0;
//     while (*s != '\0') {
//         length++;
//         s++;
//     }
//     return length;
// }

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    // [Solution with counter variable] This also passes.  It is more explicit
    // with regard to what is going on with the addresses first being calculated
    // e.g. y+i, then using the * to calculate the value at that address.  But
    // this solution is also messier.

    // int i = 0;
    // while(*(y+i) != '\0') {
    //     *(x + i) = *(y + i);
    //     i++;
    // }
    // *(x + i) = '\0';

    // [Solution w/o counter variable]:
	while (*y != '\0') {
		*x = *y;
		x++;
		y++;
	}
	*x = '\0';
}

// Sean's Solution:
// void string_copy(char *x, char *y) {
//     while (*y != '\0') {
//         *x = *y;
//         x++;
//         y++;
//     }
//     *x = '\0';
// }

// OR if you wanted to only pass the y pointer:
// void string_copy(char *y) 
// {
//     int length = string_length(y);
//     // Technically you don't need  `sizeof(char)` since characters are 1 byte
//     char *x = malloc(length * sizeof(char)); // gets you a pointer with the correct amount of memory in order to do the actual copying

//     while (*y != '\0') {
//         *x = *y;
//         x++;
//         y++;
//     }

//     *x = '\0';

//     return x;
// }


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
*/
int string_compare(char *m, char *n)
{
    // The string address is stored at m, and n BUT if you want the
    // actual value, then you need *m - which will get you the first
    // value in the m array.
    int diff = (*m - *n);
    // diff == 0 assumes pointers match.  Once diff != 0, that means
    // you have hit two pointers which do not match, whose difference
    // will be the lexocographic difference.
	while (diff == 0 && *m != '\0' && *n != '\0')
	{
		diff = *m - *n;
		n++;
		m++;
	}
    return diff;
}

// // Sean's Solution (MUCH CLEANER!):
// int string_compare(char *m, char *n) 
// {
//     while (*m == *n) {
//         if (*m == '\0') {
//             return 0
//         }
//         m++;
//         n++;
//     }
//     // if you get here, then you know that *m does NOT match *n
//     return *m - *n;
// }

// // OR THIS:
// int string_compare(char *m, char *n) {
//     for (; *m == *n; m++, n++) {
//         if (*m == '\0') { 
//             return 0
//         }
//     }
//     return *m - *n; 
// }


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
