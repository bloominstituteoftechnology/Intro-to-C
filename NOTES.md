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

# Basic Variable Types

C requires variable types to be declared.
- int: number with no decimal point
- float: number with only a few numbers after the decimal point
- double: lengthy number with decimal points
- char: a string
- arr: arrays require the length and the type of elements to be declared up front
  - arrays of chars: last char is null '\0'

```c
int i = 10;
float f = 3.24;
double d = 3.14159265359;
long double d2 = 3.141592653599999999;
char c = 'a';
int arr[5]; //(5 elems are ints of unknown value)
char str[] = 'hello';
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
syntax:
```c
#include <stdio.h>
int main () {
  int a;
  for (a=0; a<5; a= a + 1) {
   printf("value of a %d\n", a)
  }
  return 0;
}
 ```
```c
int arr[5];
 for (int i=0; i<sizeof(arr); i++) {
   arr[i] = 2 * i;
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

# Control Flow (if, else if, else, etc.)
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
# Conditionals
```c
int x = 5, y = 10, z = 15;
if ( x == 5 &&! (y < 15)) {
  
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
