

// #include <stdio.h>

// int main(void) {
    
//     printf("Hello, world!\n");

//     int x = 12; 

//     //prints 12
//     printf("x is %d\n", x);


//     // initialize a pointer p with *
//     int *p;

//     p = &x;
    
//         // printing the address that p is storing
//     printf("p is %p\n", p);
//         // printing the value that p is storing
//     printf("p is %d\n", *p);
    
//     *p = 99;
    
//     printf("%d\n", x);
    
//     // declaring a pointer
//     char *c = "Goodbye";
    
    
//     // print the actual memory address
//     printf("Address of the c pointer: %p\n", c);
    
//     // dereferencing the pointer and printing the value
//     printf("Value stored at c pointer: %c\n", *c);
    
//     for (int i = 0; i <7; i++) {
//       printf("Address: %p | Value: %c\n", c+i, *(c+i)); 
//     }
    
    
    
    
//     return 0;
// }

#include <stdio.h>

int main(void) {

    int a = 99; //int

    int* p = &a; // pointer to an int, or an int-pointer
    
    // printf("%d\n", a * 4); // print a * 4


    printf("%p\n", p); // printing the pointer to int 'a', memory address

     
    int** q = &p; // int** (pointer to a pointer)
    
    printf("%p\n", q); // printing the pointer to the pointer to int `a`
    printf("%d\n", *p); // printing the value of int 'a'
    printf("%d\n", q);
    
    char* name = "Austen";

    printf("%p\n", &name); // pritning the pointer to the char[] 'name'

    printf("%s\n", name); // printing the value of the char[] 'name'
    printf("%c\n", *name); // printing the value of the char[] 'name'

    // declaring a pointer
    char *c = "Goodbye";
    
    // print the actual memory address
    printf("Address of c pointer: %p\n", c);
    
    printf("Address of c pointer: %s\n", c);

    // dereferencing the pointer and printing the value
    printf("Value stored at c pointer: %c\n", *c);
    
    return 0;
}