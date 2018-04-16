# Dynamic Memory

Remember that a few modules ago when we were talking about arrays in C being entirely static? That's a pretty big limitation since we're forced to know up front what kind of data we want to store in the array and how much data there is before we can fit it into an array. We aren't psychics here. How do we get around this?

The answer to that is the `malloc` function. Its signature is this:
```c
    void *malloc(size_t size);
```
A `size_t` type is nothing more than a really large int for representing large sizes. The other thing to note is that the `malloc` function returns a `void` pointer. The `void` type simply means the type could be anything; essentially, we don't know the type up front. So `malloc` returns us a pointer of unspecified type that points to a chunk of memory with the specified size.

Well, if there's this `void` type, what's to stop us from just declaring everything as a `void` type? The drawback to the `void` type is that the compiler then can't infer much about our code. It doesn't know the size of a `void` pointer, plus `void` pointers cannot be dereferenced until they are _cast_ (their type is changed) to a known type. Basically, it won't be able to provide us nearly as many compile-time protections as it can if we have all of our types declared. The moral of the story is that the `void` type should only be used when you actually do not know the type of the data up front. `malloc` returning a `void` pointer is a great use-case for this.

Here are some pretty typical `malloc` calls:
```c
    int *100_ints = malloc(100 * sizeof(int));

    char *50_chars = malloc(51);
```
The first `malloc` call allocates enough space for 100 ints. The `malloc` call initially returns a `void` pointer, but it then gets _cast_ to an `int` pointer on the left-hand side. You'll also note that we're using the `sizeof` operator in order to find the size of an individual integer, and then multiplying by the number of integers we're looking to store in order to get the total amount of memory we need. We have to do this because integers are not stored in a single byte, and integer sizes may fluctuate from platform to platform.

With the second `malloc` call, you'll see we don't do that. We're still performing the cast to a `char` pointer, but there's no call to the `sizeof` operator. This is because `char`s each fit within a single byte, so 51 bytes will hold 51 `char`s, which is exactly what we want. Once we have a pointer to the `malloc`'d memory, we can work with it exactly how we've been working with pointers. 

So, we still need to know how much data we want to fit inside this chunk of `malloc`'d memory, which still isn't all that helpful since that's still a hefty limitation. There exist other library functions, such as `realloc`, which can receive a pointer to `malloc`d memory and then resize that chunk of memory, but for this module we're just going to stick with `malloc`. 

We'll talk about one of the main usages of `malloc` in the next module.
