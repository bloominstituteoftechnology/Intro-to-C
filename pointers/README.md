# Pointers

From the perspective of C, your entire computer is nothing more than a giant array of memory into which values can be written. Given this analogy, when we're dealing with arrays, how do we access some value stored inside of said array? 

We do it with indices that point to a specific spot in the array. As it turns out, pointers in C are simply just that: indices into the giant array of memory that is your computer. More formally, a pointer is a memory address that tells the program where to go and find some variable value. 

Those funky asterisks you might have seen already indicate a pointer (you might have heard them referred to as _references_ in other languages). Let's look at the function signature we had for the `reverse_string` function you wrote in the `strings` module:
```c
char *reverse_string(char s[])
{
    ...
}
```
The `char *` that is in the spot where the return type of the function usually goes is saying that this function will return a pointer to an array of characters.

It turns out that pointers and arrays in C are very much interconnected, so much so that it's pretty difficult to separate the topic of pointers from arrays. Every pointer points to the first spot of a contiguous portion of memory, and as we've already established, C pretty much just treats your computer as a giant array of memory. 

Indeed, there are many similarities between how you work with arrays and how you work with pointers. However, let's first talk about the _differences_ between them.

## Differences between arrays and pointers

Even though C let's you work with pointers and arrays in many of the same ways, don't think of them as synonomous. C's `sizeof` operator allows us to find the size of something in bytes. Let's say for example we had the following array:
```c
    int integers[] = { 9, 49, 1, 6, 10, 15 };
```
Calling `sizeof(integers)` gets us the total amount of data in the array. Then let's say we had a pointer to the same chunk of data:
```c
    int *pointer_to_integers = integers;
```
So we have an array named `integers` and a pointer called `pointer_to_integers` that points to the same spot in memory where the `integers` array is stored. If we were to call `sizeof(pointer_to_integers)`, we would actually get back the size of the pointer, not the size of the data it's pointing to.

There are a few other such sorts of edge cases, but for the most part they're pretty nuanced. So while, again, you shouldn't be thinking of pointers being arrays and vice versa, you would interface with them in many of the same ways. 

## Declaring pointers 

As showcased above, declaring a pointer is as simple as putting an asterisk after the type declaration of a variable. This signifies that we have a pointer to the declared type with the specified name. 

```c
/* Declaring two ints x and y, and an int array z */
int x = 1, y = 2, z[10];
int *ip;        /* ip is a pointer to an int */

ip = &x;        /* ip now points to x */
y = *ip;        /* y is now 1 */
*ip = 0;        /* x is now 0 */
ip = &z[0];     /* ip now points to z[0] */
```

There's nothing new going on in the first two lines of this block. Starting at the third line with `ip = &x;`, we see the `&` operator. This means we're grabbing the _address_ of the variable `x`, or in other words, we're asking for the address where the value of `x` (`1` in this case) is being stored. We do this because `ip` is a pointer, which stores an address, not a value. If we did `ip = x;`, that would be saying "store the value of the variable x in the variable `ip`", which would not compile since we've declared `ip` to be an integer pointer, not an integer value. 

In the next line, `y = *ip`, note that when we use the `*` operator not in a declaration, it signifies that we're want to grab the _value_ of the operand. So we're saying "set the variable `y` to be the value of the pointer `ip`". Again, since `ip` is a pointer, it stores an address. When we prepend the `*` operator in front of a pointer, we're asking for the value that that pointer points to. Put another way, we're indexing into the giant array of memory that is our computer and asking for the value at the given index. 

Next we have `*ip = 0;`. Here we're setting the value that `ip` points at to be 0. Before this, `ip` pointed to whatever `x`'s value was, because of the line `ip = &x;`. So now that we changed the value at some address, any other variables or pointers that also referenced that same address also got changed! If we were to print out the value of the `x` variable now, it would be `0`!

Lastly, we have `ip = &z[0];`, which declaring that `ip` now points to the first element of the `z` array. Again, we use the `&` operator in order to grab the _address_, not the _value_, of `z[0]`, since `ip` is a pointer that stores an address. 

## Pointer Arithmetic

When we index into arrays in JavaScript, we can do things like:
```javascript
    const someArray = [];

    for (let i = 0; i < array.length; i++) {
        someArray[i] = array[i + 1];
    }
```
We can index into arrays by performing arithmetic on the index. With pointers in C, we can do the exact same thing!

Let's say we have a pointer to a string like so:
```c
    char *str = "Some string";
```
We can loop through the characters in this string by doing this:
```c
    while (*str != '\0') {
        printf("%c", *str);
        str++;
    }
```
This loop will print out each character in the string. Indeed, this loop is pretty much analogous to iterating through an array. More precisely though, on each iteration of this while loop, we're incrementing the spot the pointer points to by one. At the beginning of the loop, `*str` points to the first character in the string, `S`. Then, on the next iteration, it gets incremented and then prints out `o`. This keeps going until the pointer points to the null character, which terminates the loop. 

Armed with this knowledge regarding pointers and pointer arithmetic, we can rewrite the `reverse_string` function from the last module to use pointers instead of allocating additional memory for the reversed string. This has the added benefit of performing the reverse in-place.
```c
    void *reverse_string(char *s)
    {
        char temp;
        int n = string_length(s);

        for (int i = 0; i < n/2; i++) {
            temp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = temp;
        }
    }
```

## Use cases of pointers

Lastly, let's talk a bit about why pointers are useful. The number 1 most important reason as to why pointers exists, the motivation for their invention in the first place, is that the C compiler needs every type to have a known size at compile time. This is a pretty big restriction, and it's one that comes with the territory of working in a strongly-typed language. 

But there's lots of data that we won't know the size of until runtime. What if we need to accept user input? How do we know the size of that input before the user even gives it to us? What if we need to add data to some data structure at runtime? These are all valid questions, and the workaround to them is pointers. 

We can not tell the compiler the size of certain types upfront, so what we do instead is use something of a known size to refer to things of unknown size. That is exactly what pointers are. They're a type with a known size that tells us how to access something of an unknown size. 

So whenever we need to hold something like a string or a data structure whose size depends on something that can only be known at runtime, you can bet such structures will be referred to by a pointer. 

A slightly related use case is passing by reference vs. passing by value when we're talking about passing parameters to functions. You've probably at least heard of these terms used in other languages. Passing by value means that we're passing a _copy_ of the value to a function as a parameter. This results in additional work and memory overhead, but means we have a fresh copy of the data to work with, which is desirable in certain scenarios. 

On the flip side, passing by reference means we're passing a pointer to the data. In other words, the function doesn't have access to the data itself, but it is able to find that data in memory via the passed-in pointer. There's no need to copy the data, but then that also means the function doesn't have exclusive access to the data either. 
