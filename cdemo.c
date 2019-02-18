#include <stdio.h> 
int main(void)
{
printf("Hello world !\n");

int age = 5;
float weight = 46.5;

int x[] = {1, 2, 3, 4, 5, 6};
int y[10];

char z[] = {'H', 'e', 'l', 'l', 'o', '\0'};

char *c = "Goodbye";
printf("Address of c point: %p\n", c);
printf("Value stored at c pointer %c\n", *c);

// for(int i )

int integers[] = {9, 49, 1, 6, 10, 15};
int length = sizeof(integers) / sizeof(int); // => 6
// int otherLength = sizeof(integers) // => 24
char aStr = {'H', 'e', 'l', 'l', 'o', ' ', 'G', 'o', 'o', 'd', 'b', 'y', 'e', '\0'};


char *bString = 'Hello world';
int bLength = sizeof(bString)/sizeof(char);


printf("aLength:%d\n", length);
printf("%d\n", aStr);
printf("%d\n", bString);
printf("%d\n", bLength); // double
printf("%ld\n", strlen(bLength)); // long double

// TYPES
int a = 99; //int
int *p; // pointer to an int or an int-pointer
int **q; // a pointer to an int-pointer (or a pointer to a pointer to an int)
a; // int
1 + a; //int
1.2 + a; // float
printf("%d\n", a * 4); //int
sqrt(a);  // double
// int b = sqrt(a) What would happen?
// printf("%d\n", b)
p = &a; 
p; // int *
*p; // int
&p; // int **, pointer to a pointer to an int
q = &p; // pointer to a pointer to an int on both sides, int**
q; // int **
*q; // int *
**q; //int
// Error: ***q; Since it is a triple reference to a double pointer


}