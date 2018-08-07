# Functions in C

Functions in C are not much different from functions in JavaScript. Probably the most notable difference, at least from a syntactic point of view, is that you need to specify types on all your variables and input parameters, along with needing to specify the return type of the function. Remember, C is a _strongly_ typed language, as opposed to JavaScript which is a _loosely_ typed language where types are entirely inferred by the interpreter. The C compiler ensures that you specify your types and that your code is consistent with the types you specify. 

Here is a non-comprehensive list of C data types: [https://www.le.ac.uk/users/rjm1/cotter/page_22.htm](https://www.le.ac.uk/users/rjm1/cotter/page_22.htm)

To reiterate, you might declare a function in C like this:
```c
    int foo(int param1, int param2)
    {
        ...
        return 0;
    }
```
This function signature states that it receives two integer parameters and returns an integer. 

Here's another example:
```c
    void bar(int[])
    {
        ...
    }
```
This function signature states that it receives a single integer array and doesn't return anything. You'll often see this kind of function signature when you want the function to simply mutate the input and/or print the contents of the input.

For printing output, you'll want to use the `printf` function, which is included in the `stdlib` library. 

## Implementing fizzbuzz

Your first task is going to be writing good ol' fizzbuzz in C! Your `fizzbuzz` function should receive some integer n, then loop up till n, printing out "Fizz" if the current iteration i is divisible by 3, "Buzz" if it's divisible by 5, or "FizzBuzz" if it is divisible by both 3 and 5. Additionally, for each iteration where nothing is printed, your function should increment a counter and return the result of that counter at the end of its execution. 

Navigate to the `fizzbuzz.c` file. You'll write your code in there. When you want to test it, type `make tests` into your terminal (make sure you're doing this from the directory where the `Makefile` is located), which will run the `Makefile` and compile your program and, if the compilation was successful, run the tests for it as well. 
