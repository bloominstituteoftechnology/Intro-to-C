# Projects to Do (in order)
- [ ] fizzbuzz
- [ ] strings
- [ ] pointers
- [ ] malloc
- [ ] structs
- [ ] queue
- [ ] quicksort
- [ ] [Stretch Goal] hangman

#C Syntax
// importing system
// header files
#include <stdio.h>

importing a header file
#include 'my_header_file_name-here.h'

void

main

# Basic Variable Types

C requires variable types to be declared.
- int: number with no decimal point
- float: number with only a few numbers after the decimal point
- double: lengthy number with decimal points
- char: a string (words need double quotes individual letters need single quotes)
- arr: arrays require the length and the type of elements to be declared up front; all elements are of the same type
  - arrays of chars: last char is null '\0'


```c
int i = 10;
float f = 3.24;
double d = 3.14159265359;
long double d2 = 3.141592653599999999;
char c = 'a';
int arr[5]; //(5 elems are ints of unknown value)
char str[] = 'hello'; // under the hood =>['h', 'e', 'l', 'l', 'o', '\n']
```

# Char & Char Arrays
```c
char str[] = 'hello';
strlen( str );
strcpy( str_a, str_b );
strcat( str_a, str_b );
strcmp( str_a, str_b ); invalid
```

# Loops etc

## For Loop
syntax:
```c
int a;
for (a=0; a<5; a= a + 1) {
  printf("value of a %d\n", a)
}
 ```
```c
int arr[5];
 for (int i=0; i<sizeof(arr); i++) {
   arr[i] = 2 * i;
 }
 ```
 ```c
 for (int i=1; i<= 10; i++) {
   if(i == 5) {
     continue; // skip 5
   }
   printf(i)
 }
 ```

 ## While Loop
 ```c
int done = 0;
int count = 0;
while(!done) {
  // do something
  count++;
  if(count >= 100) {
    break; // exit loop
  }
}
```

# Length, Copy, Concatanate, Compare
## Length
strlen( str )
## Copy
strcpy( str_a, str_b )

## Concatanate
strcat( str_a, str_b )

## Compare
strcmp( str_a, str_b ) invalid

# Control Flow (if, else if, else, break, continue, etc.)
```c
int x = 5, y = 10, z = 15;
if (x > y) 
{
  printf("y smaller than x");
}
else if(z % 5 == 0) 
{
  if(3 * x == z) 
  {
    printf( 'z is 3 times x' );
  }
}
else 
{
  printf( 'x, y, z are numbers' );
}
```


# Conditionals (&& || == !=)
```c
int x = 5, y = 10, z = 15;
if ( x == 5 && !(y < 15)) {
  
}
```
```c
int x = 5, y = 10, z = 15;
if( x > 0 || y > 0) {

}
```

# Boolean
False is 0
Every other number is True (usually 1 is used for True)
```c
int hungry = 1;
int thirsty = 0;
if(hungry != 0) {
  printf("I'm hungry")
} else if (!thirsty) {
  printf("I'm thirsty")
}
```

# Functions
## General Syntax
```c
return_type func_name(parameter) {
  // body of function
  // return_type could be int, str, etc. or void for no return
  // if just printing use return 0 for the last line or void type
}
```

## Void Type Example
```c
void print_sum( int x, int y) {
  printf(x+y)
}
```

# Pointers

## Declare Pointers

###Pointer to 1st character in a string
```c
char *Pointer_to_nieceName = "Samantha"; // pointer to S auto add '\0' after last 'a'
// Equivalent to:
// char nieceName = "Samantha";
// char *Pointer_to_nieceName = nieceName; // points to S

```
### Pointer to 1st item in an array

```c
int easyAs[3] = { 1, 2, 3 };
int *Pointer_to_easyAs = easyAs;
```

### Sizeof Array and Sizeof Pointer
sizeof(char) = 1 bytes;
sizeof(int) = 4 bytes;
So, when type doesn't matter for a pointer, use char since it is smaller (most granular).
Length of void items are unknown. So, it is common to have the length (in ints) included as a parameter to a function (see mem_copy).


Calling sizeof(easyAs) gets us the total amount of data in the array
```c
sizeof(easyAs);
```
Calling sizeof(Pointer_to_easyAs) size of the pointer aka sizeof an int
```c
sizeof(Pointer_to_easyAs); 
```

# Struct
Cannot initialize variables inside a struct

## Comparing using typedef and not using typedef
```c
// structure tag Pet is optional
struct Pet {  
  char[20] name;
  char[20] breed;
  int age;
} pet; //(creates an instance of struct, optional)

struct Pet pet; // other way to create an instance
```

```c
// structure tag Pet is optional
typedef struct Pet {  
  char[20] name;
  char[20] breed;
  int age;
} pet; //(creates an instance of struct, optional)

Pet pet; // other way to create an instance

strcpy(pet.name, "Sonya");
strcpy(pet.breed, "black lab");
pet.age = 14;
printf("Pet's name: %s\n", pet.name);
printf("Freed: %s\n", pet.breed);
printf("Age: %d\n", pet.age);
```

# Finding Amount of Memory
Units Reserved / sizeof(data type) => 20 / sizeof int

```c    
int another_int_array[20];
int n = 20 / sizeof(int); 

for (int i = 0; i < n; i++) {
    another_int_array[i] = i;
}
```

# What is a copy?
Having 2 things point to the same thing is not a copy. It is just 2 pointers to 1 value.
A copy would be having the same thing twice in memory.

# Sentinal Value

# Bytes etc
8 buckets
Initially Content is set to all zeros
Bucket Contents:   0 0 0 0 0 0 0 0 0 
Bucket Numbers:    0 1 2 3 4 5 6 7 8

pointer p points to bucket number
*p is the bucket contents
p++ goes to the next bucket number

# strtoul


## Example of a struct
```c
typedef struct Triangle {
    char *name;
    int height;
    int base;
} Triangle;

Triangle *createTriangle(char *name, int height, int base)
{
    Triangle *equilateral = malloc(sizeof(Triangle));
    equilateral -> name = string_dup(name);
    equilateral -> base = base;
    equilateral -> height = height;

    return equilateral;
}

void destroyTriangle(Triangle *type)
{
        if (type->name != NULL) {
            free(type->name);
        }

        if (type != NULL) {
            free(type);
        }
}

int main(void)
{
    Triangle *right = createTriangle("Right", 5, 4);
}
```