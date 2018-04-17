#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int* a, int* b)
{
	int temp = *a;
  *a = *b;
  *b = temp;
}

/*
    Given a character pointer s, returns the number of characters
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
*/
int string_length(char *s)
{
	int counter = 0;
	while (s[counter] != '\0') {
		counter += 1;
	}
	return counter;
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
	int counter = 0;
	while (y[counter] != '\0') {
		x[counter] = y[counter];
		counter += 1; 
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
*/
int string_compare(char *m, char *n)
{
	/* int counter = 0; */
	/* while	(m != '\0' || n != '\0') { */
	/* 	if (m[counter] == n[counter]) { */
	/* 		m += 1; */
	/* 	 	n += 1; */
	/* 	} else if (m[counter] > n[counter]) { */
	/* 		return 1; */
	/* 	} else if (m[counter] < n[counter]) { */
	/* 		return -1; */
	/* 	} */ 
	/* } */
	while (*m != '\0' && *n != '\0') {
		if (m < n) { return -1; }
		if (m > n) { return 1; }
		else {
			m++;
			n++;
		}
	}
	return 0;
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
    printf("Length is %d\n", string_length(buffer));
    printf("Comparison is %d\n", string_compare(hello, world));

    return 0;
}
#endif
