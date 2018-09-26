// Just like in JS, comments in C use two slashes

// This first line has us including a `.h`, which is
// called a header file in C. This particular header
// file is called 'standard IO', and we need it to
// print output from our program
#include <stdio.h>

// Here we're defining a function in C. Instead of doing
// that with a `function` or `def` keyword, we prepend
// the function definition with the return type of the
// function. The return type is the type of whatever
// output the function returns. In the case of this
// `hello_world` function, it returns an integer, 0
// in this case. The `void` function parameter means
// this function doesn't accept any parameters.
int hello_world(void)
{
  // The `printf` function comes from stdio.h.
  // It's analogous to `print()` in Python or
  // `console.log()` in JS. Here we're just
  // printing out a string followed by a newline.
  printf("Hello World\n");
  return 0;
}

// EXERCISE: Define another function that prints
// "Hello World Again!\n". Instead of returning
// 0 like the first function did, don't have this
// one return anything. What will its return type
// need to be?

void hello_world_again(void)
{
  printf("Hello World Again!\n");
}

// This `print_int_array` function is receiving an
// array that contains integers as well as the
// length of the array. Arrays in C can only hold
// a single type.
int print_int_array(int arr[], int length)
{
  // For loops and while loops in C are pretty much
  // unchanged from the ones you know and love from
  // JS. The only difference in order to declare the
  // counter `i`, we have to declare it as an `int`
  for (int i = 0; i < length; i++)
  {
    // Here we want to perform some string interpolation
    // in order to print the ith array element. C does
    // this with what are called 'format specifiers'.
    // Each type has its own format specifier. In this
    // case, the format specifier for an integer is 'd'
    // which stands for 'digit'. Don't forget the newline,
    // otherwise all the values will be printed on the
    // same line.
    printf("%d \n", arr[i]);
  }

  return 0;
}

// This `print_input_string` function receives a string
// as input.
int print_input_string(char *string)
{
  // EXERCISE: Look up how to print a string in C
  // Print out the input string
  // Don't forget the newline
  printf("%s \n", string);
  return 0;
}

// Another significant difference between C and JS/Python is
// that any code that we want executed needs to live inside a
// function called `main` (yes, it has to be named `main`).
// This is typically true for all low-level systems languages
// since these languages are all compiled languages. We'll
// need to invoke our defined functions inside `main`.
int main(void)
{
  // Declaring some variables just for fun
  int age = 34;
  float weight = 138.53;

  // Declaring an array of integers
  // Yep, arrays in C are declared with curly braces
  // The empty square brackets denote this to
  // be an array
  int arr_of_ints[] = {9, 4, 5, 2, 8, 5, 6};

  // EXERCISE: Look up how to find the number of elements
  // in an array. Find the length of the `arr_of_ints` array.
  // Store that value in the `len` variable.
  int len = sizeof(arr_of_ints) / sizeof(arr_of_ints[0]);

  // We could also declare an empty array like this.
  // This array is statically allocated to hold 10
  // integers, but it's initialized with nothing in it.
  int second_arr_of_ints[10];

  // This would initialize an empty array with nothing
  // inside it and with no space allocated for it. In
  // its current form, it's entirely useless.
  int useless_arr[0];

  // Declaring a string
  // We're going to talk about the asterisk in the C lecture
  char *string = "Goodbye World";

  // We could also declare a string like this
  // Here it's being explicitly declared as an array of chars
  // Note the '\0' character at the end of the array
  char another_string[] = {'H', 'i', ' ', 't', 'h', 'e', 'r', 'e', '\0'};

  // Call our `hello_world` function
  hello_world();

  // EXERCISE: Call your function that prints "Hello World Again!" here!
  hello_world_again();

  // Call our `print_int_array` function
  print_int_array(arr_of_ints, len);

  // Call our `print_input_string` function
  print_input_string(string);

  char *s = "Testing";
  printf("%s\n", s);
  char *t = s;
  printf("%s\n", t);
  char u[] = "Testing 1, 2, 3";
  printf("%s\n", u);
  char *w = u;
  printf("%s\n", w);

  return 0;
}