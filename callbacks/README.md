# Function Pointers

Why is this module titled 'callbacks'?! Didn't we leave those behind in JavaScript??! 

Well, if you think about it, JavaScript engines (notably V8) are implemented in C++, which would imply that callbacks can be implemented in C. That's what this module is all about, giving you a little taste of how callback functions are implemented under the hood. Isn't that exciting?!

So let's go back to the basics. At the lowest level, what is a function? A function in C is nothing more than a pointer to a spot in the program where some code exists. The pointer will point to the first instruction in the function, which a processor will then execute when the function is called. Thus, callbacks can entirely be implemented as nothing more than function pointers that get passed around as function arguments and invoked from other functions. 

A function pointer will have the following signature:
```c
    int (*function_pointer_name) (int a, int b);
```
Note that really the only difference between a function pointer and a function that returns a pointer is simply the parentheses around the name of the function pointer. 

## Using function pointers

There's some setup that needs to occur before we can easily utilize function pointers as callback functions. It pertains to the fact that function pointers don't have an inherent type associated with them. Sure, they return a type, since they're functions, but there's no `function_pointer` type specified in the C language. That needs to be alleviated in order for us to pass function pointers into other functions. 

Let's say we have the following function pointer signature:
```c
    void (*callback) (char *str);
```
We'll need to go and define a type for this function. C provides the `typedef` operator as a way to alias some definition into it's own type. The `typedef` operator's other main use is to create new types from defined structs. But anyways, we'll use it to create a function pointer type like so:
```c
    typedef void (*callback) (char *str);
```
Voilà! We've created a callback type which can now be passed into another function like this:
```c
    void foo(callback cb);
```
Keep in mind though that this callback type is specifically a function pointer that has a `void` return type and only accepts a single string as argument. If we wanted to define another callback function with a different signature, we'd have to `typedef` it separately. 

For this module you'll be implementing a bubble sort function that accepts a callback. The callback will be the specifier of the order that the bubble sort should be sorting the input into. It's very much like JavaScript's `Array.sort` method that accepts a callback. This makes the sort function slightly more generic. 

Take a look at `callbacks.h`. There you'll see the type declaration for the function pointer callback that you'll implement as part of this module. 

Inside of `callbacks.c`, you'll define the two functions that will be passed as callbacks to the `bubble_sort` function that you'll also implement as part of this module. 