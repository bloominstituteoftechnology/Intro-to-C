# Structs

Another limitation that exists in C that we haven't brought up yet is the fact that arrays in C can only hold a single type of data. Being able to stick any type of data all into the same array is a feature that you probably take for granted coming from JavaScript. Well, you can't do that in C!

Enter structs. Structs are basically C's version of a poor man's object. We can store values of different types inside a struct, which is awesome, but we need to declare the types of the fields that the struct can hold up front. That being said, structs are instrumental when it comes to implementing data structures and more complex types in C. 

## Initializing structs

Let's look at a simple struct definition:
```c
    struct Cat {
        char *breed;
        char *color;
        int age;
    };
```
This declares the shape of the Cat struct. Now we'll need to create an instance of it if we want to want to actually use it. Well, what actually defines an instance of something?

In this case, an instance of a struct is some chunk of memory that has been initialized with the shape of said struct. So we'll need to allocate memory for our Cat struct. We can do that with this:
```c
    struct Cat *a_cat = malloc(sizeof(struct Cat));
```
So we're handed a pointer to a chunk of memory that holds exactly the right amount of data for a single instance of a Cat. We take that and cast it to a pointer with the type of `struct Cat` since that's the type that is being held in this chunk of memory. We'll also need to go and initialize the values of our Cat instance like so:
```c
    a_cat->breed = NULL;
    a_cat->color = NULL;
    a_cat->age = -1;
```
What's with these funky arrows? Coming from JavaScript, you're used to using dot notation for accessing members of an object. Structs are poor man's objects, so shouldn't dot notation work here?

The answer is that dot notation is a thing in C, but because in this case we have a _pointer_ to a struct, we need to perform a dereference first in order to get to the actual data the struct contains. That's what the arrow syntax does. It performs a dereference first and then accesses the struct member. 

Basically, you can think of it like this:
```c
    a_cat->breed == *(a_cat).breed
```

Allocating memory for structs is one of the most important functions that `malloc` serves. Keep in mind though that when we declare a struct, every type in the struct needs to have a known size. Looking at the Cat struct, `char *`s and `int`s all have a known size, so the entire size of the struct can be calculated. However, we don't know the sizes of the data that the `char *`s may be pointing to. 

Let's say we have a function called `name_cat` that will assign a Cat instance with a given input name. It might look like this:
```c
    void name_cat(struct Cat *cat, char *name)
    {
        int name_length = string_length(name);

        cat->name = malloc(name_length);
        string_copy(cat->name, name);
    }
```
That's right, we'll need to call `malloc` to allocate the appropriate amount of memory to the `cat->name` field, and then we can call `string_copy` in order to copy each character in the input `name` string to the memory that `cat->name` now points to. 

## Freeing memory

Yet another abstraction that you're used to from higher-level languages is the garbage collector. A garbage collector is typically part of a language's runtime, and its job is to clean up memory that is used up by your programs. 

For example, after you write some JS program that has a bunch of arrays and objects, what happens to the memory that was needed to order to hold those instances? In a high-level language, a garbage collector goes through and figures out that those arrays and objects are no longer being used. It then deallocates or frees up that memory so that it can be reused by other programs. You the programmer never needs to worry about cleaning up after yourself; it's all handled for you automatically!

C doesn't baby you around like that. It expects _you_ to handle the clean up like the grown up you are. Learning to clean up after yourself can get difficult when you're writing more advanced programs in C. For simple programs though, it can be as simple as calling the function `free` after you're done with some piece of `malloc`'d memory. 

The `free` function receives a pointer that points to a piece of `malloc`'d memory, and it deallocates it so that that memory may be re-used. As you can imagine, once some `malloc`'d memory has been `free`'d, whatever data was in that chunk of memory is gone, so make sure you're done with the data before `free`ing it!

Let's codify this into a simple heuristic that isn't too hard to memorize: 
> For every call to `malloc` there should be an accompanying call to `free`.

A couple of common errors that arise when it comes to `free`ing memory are:
1. Forgetting to call `free` on some `malloc`'d piece of memory. This is a problem because that memory doesn't get cleaned up, and you end up with what's called a 'memory leak'. A single memory leak isn't the end of the world, but if you continually forget to `free` your memory, they'll start to pile up and waste precious memory resources that could be used by other programs that actually need that memory. 
2. Calling `free` on a pointer to memory that has already been `free`'d. This is called a 'double free', and it should be avoided because it may corrupt the state of the memory manager (which is what keeps track of all of the pieces of memory that have been handed out so far), which might cause existing blocks of memory to get corrupted or for future allocations to fail in bizarre ways (for example, the same memory getting handed out on two different successive calls of malloc).

Going back to our Cat struct, we might want to have a `Cat_destroy` function that will handle the cleaning up of a Cat instance for us. It'll free all the memory that was allocated during the Cat instance's lifetime.
```c
    void Cat_destroy(struct Cat *cat)
    {
        if (cat->name != NULL) {
            free(cat->name);
        }

        if (cat->breed != NULL) {
            free(cat->breed);
        }

        if (cat != NULL) {
            free(cat);
        }
    }
```
