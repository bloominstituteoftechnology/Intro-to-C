#include <stdio.h>

int main() {
  // A pointer saves the physical address of a value
  int a = 1; // Declaring integer variables and saving integers to the variables
  int b = 2; 
  int pointerMath;

  // Declaring integer pointers but not pointing to any addresses just yet
  int *x; 
  int *y;

  // Saving an integer pointer to the address of an integer variable
  x = &a; // Remember that using an `&` means it's an address
  y = &b; 

 /* 
  x = a will compile, but it will provide a warning and makes utlizing the 
  pointer for math later, impossible. This is because we aren't specifying 
  that we're creating a pointer, by directly looking for an address with `&`.
  */
 
  printf("Pointer x output looking for a POINTER ->  %p\n", x); // -> [Address]
  printf("Pointer x output looking for an INT ->  %d\n", x);    // -> [Address] WARNING
  printf("Pointer x output looking for an INT ->  %d\n", *x);   // -> 1 (value)
  /* What is the meaning of this?! ^
  Without the asterisk we get a memory address
  With an asterisk we get the value at that address
  */

  // Using the values stored at the addresses contained in the pointers
  pointerMath = *x + *y;
  printf("Adding two values that `x` and `y` point to ->  %d\n", pointerMath);          // -> 3

  // Can we change the value stored within a pointer?
  *x = 10;
  printf("Changing the value of pointer x -> %d\n", *x);        // -> 10 YES

  return 0;

  /* Take Away
  Pointers are just like any variable. The main difference is that they store
  the address of a variable rather than it's direct value.
  
  This means that no matter the scope of our program, we have a stored reference to something that
  lives at a particular place. We can still modify or view that value, or if we so choose, simply
  view the address of whatever lives there.
  */
}