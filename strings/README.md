# Arrays in C

In C, arrays are nothing more than contiguous chunks in memory that store a _single_ type of data. Additionally, arrays are static in size, at least in their most basic form. That means that we'll typically need to know the size and/or the amount of data a particular array will be storing when we initialize it. Unlike in higher-level languages, we can't just simply declare an empty array and then start pushing elements onto it willy-nilly.

If we wanted to declare an array of integers, we might do it like so:
```c
    int int_array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
```
Note the syntax here. We need the square brackets after the array's name to indicate that it is an array to the compiler, and when we declare the initial values of the array, we surround them with curly braces, not square brackets. 

Another way we might declare an array is the following:
```c
    int another_int_array[20];
```
With this, we've declared a statically-sized integer array that has space for 20 bytes worth of integers. There's nothing in it initially, but we can now start populating it with integers (and only integers) up to it's specified capacity. 
```c
    int n = 20 / sizeof(int);

    for (int i = 0; i < n; i++) {
        another_int_array[i] = i;
    }
```
While we allocated 20 bytes worth of space into the array, keep in mind that a single integer actually takes up more than a single byte of space in memory. To get around this, we can use the `sizeof` operator to find out exactly how many bytes a single `int` occupies on your machine, and then divide the array capacity by that to get the actual number of integers that can fit inside the array.

If we try to add more integers than the array has capacity for, we'll get a segmentation fault error, which means we've tried to access memory we don't have permission to access. That's what happens when we go outside of an array's bounds. 

We'll talk later on about how to handle dynamically-sized data. 

# Strings in C

So what do arrays have to do with strings? Everything, as it turns out. Strings in C are actually nothing more than arrays of characters. In fact, when declaring a string, you might do it like this:
```c
    char[] = "Hello world!";
```
Under the hood, this declaration becomes
```c
    char[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\0' };
```
The `\0` character at the end represents the null character; _every_ C string is terminated with one of these, and in fact, if you wanted to write a function to find the number of characters in a string, you'd basically just loop through the character array and increment a counter until you found the `\0` character. 

IMPORTANT NOTE: So far, every language you've worked in has not differentiated between single and double quotes. In C, these actually make a difference. Single quotes delineate a single character, while double quotes delineate string literals. So for example, `"a"` is a string literal complete with a terminating null character at the end of it, as opposed to `'a'` which is just the individual character. 

The compiler _will_ yell at you if you try to store multiple characters in single quotes. 