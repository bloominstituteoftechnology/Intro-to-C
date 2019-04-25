# Intro to C FAQ

## Contents

### Common Errors

* [`runtests.sh: $'\r': command not found` or `Syntax error: word unexpected (expecting "do")`](#q100)
* [`runtests.sh: 56059 Segmentation fault: 11  $VALGRIND`](#q200)
* [Mac: `malformed object` error when running `make tests`](#q300)
* [What does the "implicit declaration of function" warning mean?](#q1500)
* [What is a segmentation fault and how do I stop it?](#q2100)
* [What's the `incompatible integer to pointer conversion` error?](#q3400)
* [What is an `undefined symbol` linker error?](#q5300)
* [What is "undefined behavior" in C?](#q5000)
* [Should I bother fixing compiler warnings?](#q400)

### General C

* [Can I accidentally destroy my computer running C code?](#q500)
* [Why do we subtract '0' from a char to convert it from ASCII to a numeric value?](#q1100)
* [What's the difference between `puts()`, `fprintf()`, and `printf()`?](#q1600)
* [Why does `025 == 21`?](#q1700)
* [What is the "true dev workflow" in C?](#q1800)
* [Does C have garbage collection?](#q1900)
* [Why is C code faster than other languages?](#q2000)
* [Are variables automatically initialized to zero when I declare them?](#q2500)
* [What VS Code plugins are good for C development?](#q2700)
* [What are some additional C resources?](#q2800)
* [How do I get the debugger working?](#q2900)
* [Does C have closures?](#q3100)
* [If I look at an uninitialized variable, will the garbage in it ever be leftover data from another process?](#q3200)
* [What are `stdin`, `stdout`, and `stderr`?](#q3900)
* [How do I know which header files to `#include` for any particular function?](#q4000)
* [What are bits, bytes, kilobytes, megabytes, and all that?](#q4400)
* [What's the difference between `#include` with double quotes and `#include` with angle brackets?](#q4600)
* [Why does `main()` return `0`? What does the return value mean?](#q5800)
* [Is there a difference between `exit()` and `return`?](#q4800)
* [What is "undefined behavior" in C?](#q5000)
* [How do I write preprocessor macros with `#define`?](#q5200)
* [How do I make my own header files and what do I put in them?](#q5400)
* [How do I make my own Makefile?](#q5500)
* [Why are there so many `printf()` variants? How do I know which one to use?](#q5600)
* [Why is `main()` always at the bottom of the file?](#q5700)
* [Do we have to have a `main()`? Can there be more than one?](#q5900)
* [Can `main()` return `void`? What about `main()` with no parameters?](#q6000)
* [Do we need a semicolon at the end of every line?](#q6100)

### Strings

* [Can you use `+` to concatenate two strings?](#q2400)
* [For string literals like `"Hello"`, are those stored on the stack or heap?](#q3600)
* [Why does `strcmp()` return `0` when strings match? Since `0` means "false" in C, that seems backwards.](#q4900)

### Structs

* [Is a `struct` comparable to something in Python or JS? Is it like a class?](#q600)
* [Can you have default parameters in the structs?](#q700)
* [Why do functions tend to return pointers to structs, and not just copies of the struct?](#q1000)

### Types

* [Why does unsigned char type accept a number when it's clearly referring to a character?](#q800)
* [What's the difference between a `float` and a `double`, or between an `int` and a `long`?](#q2300)
* [What type should I use to hold numbers bigger than an `int` can hold?](#q2600)
* [When do I have to explicitly cast a type to another type?](#q4100)
* [In C, can we assume an `int` is 32 bits?](#q4500)

### Arrays

* [When I pass an array as an argument to a function, when do I use pointer notation and when do I use array notation ?](#q900)

### Pointers

* [When I pass an array as an argument to a function, when do I use pointer notation and when do I use array notation ?](#q900)
* [Why do functions tend to return pointers to structs, and not just copies of the struct?](#q1000)
* [When do I need a pointer to a pointer?](#q1200)
* [Do other languages use pointers?](#q1300)
* [What's the difference between "`int *x`" and "`int* x`"?](#q1400)
* [How do I print a pointer with `printf`?](#q3000)
* [How many levels of indirection can you have with pointers? `int******`?](#q3300)
* [What's the `incompatible integer to pointer conversion` error?](#q3400)
* [Should I declare a pointer to a thing, or just declare the thing?](#q4700)
* [When you free a pointer, does it get set to `NULL` automatically?](#q5100)
* [Can a pointer pointer to more than one thing? What about to arrays and `struct`s?](#q6200)
* [If variables are stored in memory, where are pointers stored?](#q6300)

### Heap, Stack, Dynamic Memory

* [What happens if my program exits but I forgot to `free()` some memory I allocated?](#q2200)
* [Are there any other ways besides `malloc()` to store things on the heap?](#q3500)
* [Is the C stack like the stack data structure?](#q3700)
* [Is the C heap like a binary heap data structure?](#q3800)
* [Is `realloc()` the same as calling `malloc()`, copying the data over, then calling `free()` on the original pointer?](#q4200)
* [What happens if I `free()` a `NULL` pointer?](#q4300)
* [When you free a pointer, does it get set to `NULL` automatically?](#q5100)

## Questions

<a name="q100"></a>
### `runtests.sh: $'\r': command not found` or `Syntax error: word unexpected (expecting "do")`

If you see this error:

```shell
Running unit tests:
: not foundtests.sh: 2: ./tests/runtests.sh:
./tests/runtests.sh: 4: ./tests/runtests.sh: Syntax error: word unexpected (expecting "do")
```

You have two options:

1. Open the file `tests/runtests.sh` in VS Code in whatever subproject folder
   you’re working in, e.g. `fizzbuzz`. Click on the lower right of the screen
   where it says `CRLF`. Choose `LF`. Save the file. Then the error should go
   away.

2. You can do this from the command line with the `tr` command:

```shell
cd tests
cat runtests.sh | tr -d '\r' > runtests.tmp
mv runtests.tmp runtests.sh
```

The root of the problem is a setting in git that causes all newlines (LF) to
be converted to carriage-return/newline (CRLF). The script `runtests.sh` is a
_bash script_ that bash runs, and bash *hates* `\r` and pukes everywhere.

To cause git to _not_ do newline conversion for future clones, run the
following:

```
git config --global core.autocrlf false
```

------------------------------------------------------------------------

<a name="q200"></a>
### `runtests.sh: 3: 56059 Segmentation fault: 11  $VALGRIND`

This means you got a segfault in your program. See [What is a segmentation fault
and how do I stop it?](#what-is-segfault)

------------------------------------------------------------------------

<a name="q300"></a>
### Mac: `malformed object` error when running `make tests`

This is caused by an older version of the `ar` and `ranlib` packages being installed.
Sometimes these conflict with the versions installed with xcode.

If running MacPorts:

```
sudo port selfupdate
sudo port upgrade cctools
```

If running Brew:

```
sudo brew update
sudo brew upgrade gcc
```

------------------------------------------------------------------------

<a name="q400"></a>
### Should I bother fixing compiler warnings?

YES!

In C, a warning is the compiler saying, "I can build that, and I will, but it's
probably going to do something really messed up that you don't want."

There are only a few warnings you can safely ignore.

If you're _absolutely sure_ the "unused variable" warning is OK, then you could ignore it. Or, better, add a line of code that silences the warning:

```c
void foo(int a)
{
    (void)a; // Do nothing, but at least the compiler will be quiet
```

------------------------------------------------------------------------

<a name="q500"></a>
### Can I accidentally destroy my computer running C code?

Nope! Not with a modern OS.

If you're running MS-DOS, then sure, you can do all kinds of things.
I once accidentally blew away all my BIOS settings with a program I
wrote and my computer wouldn't boot.

But Windows, Linux, macOS, BSD, or any other mainstream OS from this century all
offer memory and resource protection that prevents you from changing memory
you're not supposed to, or wiping out a disk you're not supposed to, etc.

The worst you'll see is a `Segmentation fault` message which means your program
tried to do something bad and the OS killed it.

------------------------------------------------------------------------

<a name="q600"></a>
### Is a `struct` comparable to something in Python or JS? Is it like a class?

It's like a class, except with only data (fields, properties) attached to it.
There are no methods (functions) associated with it.

If you _really_ want to pretend that you have methods on a `struct`, you can add
them as fields that are _pointers to functions_. The syntax is pretty obtuse,
and it's not a natural or idiomatic thing to do in C.

Example:

```c
struct animal {
    char *name;

    // make_sound is a pointer to a function with no parameters that returns void
    void (*make_sound)(void);
}

// Note how bleat() matches the signature for make_sound(), above
void bleat(void)
{
    printf("Baaaahhhh!\n");
}

int main(void)
{
    struct animal goat;

    // C doesn't have the concept of a constructor, so we have to do it by hand:

    goat.name = "goat";
    goat.make_sound = bleat;

    // Call the "method":

    goat.make_sound(); // Baaaahhhh!
}
```

------------------------------------------------------------------------

<a name="q700"></a>
### Can you have default parameters in the structs?

No. The best you can do is have a helper function set the defaults.

```c
void foo_default(struct foo *f)
{
    f->a = 10; // Set defaults
    f->b = 20;
    f->c = 30;
}
```

```c
struct foo x;

foo_default(&x); // Set defaults

x.a = 99; // Override default
```

When you declare a `struct`, you can also use an initializer to set the field
values:

```c
struct foo x = { .a = 10, .b = 20, .c = 30 };
```

------------------------------------------------------------------------

<a name="q800"></a>
### Why does unsigned char type accept a number when it's clearly referring to a character?

Deep down, computers just deal in numbers (`1`s and `0`s). They don't know what
a character is. We humans have come up with a system wherein a number
_represents_ a certain character. For example, we've agreed that `A` is `65`.

(For information on what number represents what character, look up more detail
on [ASCII](https://en.wikipedia.org/wiki/ASCII) encoding, or its modern superset
[UTF-8](https://en.wikipedia.org/wiki/UTF-8).)

With that in mind, C really only deals in numbers. Even when you put a character
in single quotes, it's still just a number. The only difference is in how we
_interpret_ that number. That is, is it a value, like 65, or is it a character,
like `A`?

```c
unsigned char c = 'A';

printf("%c\n", c); // Prints "A"
printf("%d\n", c); // Prints 65
```

```c
unsigned char c = 'A';
int x = c + 10;

printf("%d", x); // Prints 75, since 'A' == 65
```

In C, whenever you have a character in single quotes like `'A'`, the compiler
treats it just like you'd put the number `65` there. (Or `66` for `'B'`, and so
on.)

The only difference between `unsigned char` and `unsigned int` is the number of
bytes that are used to represent the number. A `char` is onGe byte, and an `int`
is typically 4 bytes (but not always).

You can think of these additional bytes as analogous to adding more digits to
your numbers. The more digits you have, the more range you can store. Two
decimal digits only gets you from 0 to 99, but 8 digits gets you from 0 to
99999999. Similarly, one byte only gets you from 0 to 255, but 4 bytes gets you
from 0 to 4,294,967,295.

If you never needed numbers larger than 255, you could use `unsigned char` for
all your variables! (But since modern computers are at least as fast with `int`s
as they are with `char`s, people just use `int`s.)

------------------------------------------------------------------------

<a name="q900"></a>
### When I pass an array as an argument to a function, when do I use pointer notation and when do I use array notation ?

It's a little-known FunFact that C doesn't actually pass entire arrays to
functions. It only passes pointers to the first element in that array.

```c
int a[2000];

// "a" is a pointer to the first element in the array.
// It's the same as &(a[0]).
foo(a);
```

So when you declare your function, you can do any of these:

```c
void foo(int *a)
```
```c
void foo(int a[])
```
```c
void foo(int a[1])
```
```c
void foo(int a[2000])
```
```c
void foo(int a[999999999])
```

and it treats them all as if you'd used:

```c
void foo(int *a)
```

There's a difference if you want to use multidimensional arrays. You must
declare all the dimensions except the first one, which is optional. The compiler
needs to know the other dimensions so it can do its array indexing computations
correctly.

```c
int foo(int x[][30]) // 30 wide
{
    return x[2][4];
}

int main(void)
{
    int a[10][30]; // 30 wide

    foo(a);
```

This only applies for multidimensional arrays. For 1-dimensional arrays, the
rule still applies; you still need to specify all dimensions except the first
one... but since there is only one, you never need to specify it.

------------------------------------------------------------------------

<a name="q1000"></a>
### Why do functions tend to return pointers to structs, and not just copies of the struct?

It's possible to do this:

```c
struct foo my_func(void)
{
    struct foo f;

    f.x = 10;

    return f; // Return a copy of f
}
```

as opposed to:

```c
struct foo *my_func(void)
{
    struct foo *p = malloc(sizeof(struct foo));

    p->x = 10;

    return p; // Return a copy of p
}
```

But in C, it's more idiomatic to return a copy of the pointer to the memory
allocated than it is to return a copy of the `struct` itself.

Part of the reason for this is that it takes time to copy data. A `struct` can
be very large depending on how many fields it has in it, but your average
pointer is only 8 bytes.

Since every time you `return` a thing, a copy of that thing gets made, it is
faster to copy a pointer than it is to copy a `struct` of any non-trivial size.

Finally, note that this variant always invokes undefined behavior and should
never be used:

```c
struct foo *my_func(void)
{
    struct foo f;

    f.x = 10;

    return &f; // Return a copy of a pointer to f
}
```

The reason is because `f` vaporizes as soon as the function returns (since it's
just a local variable), so any pointers to it are invalid.

------------------------------------------------------------------------

<a name="q1100"></a>
### Why do we subtract '0' from a char to convert it from ASCII to a numeric value?

The code typically looks like this:

```c
char c = '2';  // ASCII '2'

int v = c - '0'; // Convert into numeric value 2

printf("%d\n", v); // prints decimal 2
```

Remember that in C, a `char` is like a small `int`, and when you have a
character in single quotes like `'2'`, C replaces that with the
[ASCII](https://en.wikipedia.org/wiki/ASCII) value of that character.

In the case of our example, the ASCII value of `'2'` is `50`. And we want to
convert that to the numeric value `2`. So we clearly have to subtract `48` from
it, since `50 - 48 = 2`. But why the `'0'`, then?

Here's part of the ASCII table, just the numbers:

|Character|ASCII value|
|:-------:|:---------:|
|  `'0'`  |    48     |
|  `'1'`  |    49     |
|  `'2'`  |    50     |
|  `'3'`  |    51     |
|  `'4'`  |    52     |
|  `'5'`  |    53     |
|  `'6'`  |    54     |
|  `'7'`  |    55     |
|  `'8'`  |    56     |
|  `'9'`  |    57     |

It's no coincidence it's done this way. Turns out that if you subtract `48` from
any ASCII character that is a digit, you'll end up with the numeric value of
that ASCII character.

Example: `'7'` is value `55` (from the table), compute `55 - 48` and you get
`7`.

And since `'0'` is `48`, it's become idiomatic in C to convert ASCII digits to
values by subtracting `'0'` from them.

------------------------------------------------------------------------

<a name="q1200"></a>
### When do I need a pointer to a pointer?

There are a few reasons you might need one, but the most common is when you pass
a pointer to a function, and the function needs to modify the pointer.

Let's take a step back and see when you just need to use a pointer.

```c
void foo(int a)
{
    a = 12;
}

int main(void)
{
    int x = 30;

    printf("%d\n", x); // prints 30

    foo(x);

    printf("%d\n", x); // prints 30 again--not 12! Why?
}
```

In the above example, `foo()` wants to modify the value of `x` back in main.
But, alas, it can only modify the value of `a`. When you call a function, all
arguments get _copied_ into their respective parameters. `a` is merely a _copy_
of `x`, so modifying `a` has no effect on `x`.

What if we want to modify `x` from `foo()`, though? This is where we have to use
a pointer.

```c
void foo(int *a)
{
    *a = 12; // Set the thing `a` points at to 12
}

int main(void)
{
    int x = 30;

    printf("%d\n", x); // prints 30

    foo(&x);

    printf("%d\n", x); // prints 12!
}
```

In this example, `foo()` gets a copy of a pointer to `x`. (Everything gets
copied into the parameters when you make a call, even pointers.)

Then it changes the thing the pointer points to to `12`. That pointer was
pointing to `x` back in main, so it changes `x`'s value to `12`.

Great!

So what about pointers to pointers? It's the same idea. Let's do a broken
example:

```c
void alloc_ints(int *p, int count)
{
    p = malloc(sizeof(int) * count); // Allocate space for ints
}

int main(void)
{
    int *q = NULL;

    alloc_ints(q, 10); // Alloc space for 10 ints

    printf("%p\n", q); // Prints NULL still!!

    q[2] = 10;  // UNDEFINED BEHAVIOR, CRASH?
}
```

What happened?

When we call `alloc_ints()`, a _copy_ of `q` is made in `p`. We then assign into
`p` with the `malloc()`, but since `p` is just a copy of `q`, `q` is unaffected.

It's just like our first version of `foo()`, above.

Solution? We need to pass a pointer to `q` to `alloc_ints()` so that
`alloc_ints()` can modify the value of `q`.

But `q` is already a pointer! It's an `int *`! So when we take the address-of it
(AKA get a pointer to it), we'll end up with a pointer to a pointer, or an `int
**`!

```c
void alloc_ints(int **p, int count)
{
    // Allocate space for ints, store the result in the thing that
    // `p` points to, namely `q`:

    *p = malloc(sizeof(int) * count);
}

int main(void)
{
    int *q = NULL;

    alloc_ints(&q, 10); // Alloc space for 10 ints

    printf("%p\n", q); // Prints some big number, good!

    q[2] = 10;  // works!
}
```

Success!

------------------------------------------------------------------------

<a name="q1300"></a>
### Do other languages use pointers?

Most all of them do, but some are more explicit about it than others. In
languages like Go, C, C++, and Rust, you have to use the proper operators when
using pointers and references.

But languages like JavaScript and Python do a lot of that stuff behind your
back. Take this Python example:

```python
class Foo:
    def __init__(self, x):
        self.x = x

def bar(a):
    a.x = 12 # Sets `f.x` to 12--why?

    a = None # Does NOT destroy `f`--why not?


f = Foo(2)

print(f.x) # Prints 2

bar(f)

print(f.x) # Prints 12--why?
```

Let's look what happened there. We made a new object `f`, and we passed that
object to function `bar()`, which modified its `x` property.

After enough time with Python, we learn that it passes objects _by reference_.
This is another way of saying it's using pointers behind your back. Behind the
scenes in Python, `a` is a pointer to `f`.

That's why when we modify `a.x`, it actually modifies `f.x`.

And it's also why when we set `a` to `None`, it doesn't change `f` at all. `a`
is just a pointer to `f`, not `f` itself.

Let's look at the C version of that Python program. This works exactly the same way:

```c
#include <stdio.h>

struct foo {
    int x;
};

void bar(struct foo *a)
{
    a->x = 12;   // Sets f.x to 12--why?

    a = NULL;    // Does NOT destroy `f`--why not?
}

int main(void)
{
    struct foo f = { 2 };

    printf("%d\n", f.x); // Prints 2

    bar(&f);

    printf("%d\n", f.x); // Prints 12--why?
}
```

`a` is a pointer to `f`. So we when do `a->x`, we're saying "set the `x`
property on the thing that `a` points to".

And when we set `a` to `NULL`, it's just modifying `a`, not the thing that `a`
points to (namely `f`).

------------------------------------------------------------------------

<a name="q1400"></a>
### What's the difference between "`int *x`" and "`int* x`"?

Syntactically, nothing. They're equivalent.

That said, the recommendation is that you use the form `int *x`.

Here's why. These two lines are equivalent:

```c
int* x, y;
```

```c
int *x, y;
```

In both of them, `x` is type `int*`, and `y` is type `int`. But by putting the
asterisk right next to the `int`, it makes it look like both `x` and `y` are of
type `int*`, when in fact only `x` is.

If we reverse the order of `x` and `y`, we must necessarily move the asterisk
with `x`:

```c
int y, *x; // Also equivalent to the previous two examples
```

It's idiomatic to keep the asterisk tucked up next to the variable that's the
pointer.

------------------------------------------------------------------------

<a name="q1500"></a>
### What does the "implicit declaration of function" warning mean?

This is the compiler saying "Hey, you're calling a function but I haven't seen a
declaration for that function yet." Basically you're calling a function before
you've declared it.

If you're calling a library function like `printf()` or a syscall like `stat()`,
the most common cause of this warning is failure to `#include` the header file
associated with that function. Check the `man` page for exactly which.

But what if you're getting the error on one of your own functions? Again, it
means you're calling that function before you've declared it.

But what does _declared_ mean?

A declaration can either be a function definition, or a function prototype.

Let's look at a broken example:

```c
#include <stdio.h>

int main(void)
{
    foo(); // Implicit declaration warning!!
}

void foo(void)
{
    printf("Foo!\n");
}
```

In that example, `main()` calls `foo()`, but the compiler hasn't seen a
declaration of `foo()` yet. We can fix it by defining `foo()` _before_ `main()`:

```c
#include <stdio.h>

// Just moved foo()'s definition before main(), that's all

void foo(void)
{
    printf("Foo!\n");
}

int main(void)
{
    foo(); // No problem!
}
```

You can also use a _function prototype_ to declare a function before it is used,
like so:

```c
#include <stdio.h>

void foo(void); // This is the prototype! It's a declaration of foo().

int main(void)
{
    foo(); // No problem
}

void foo(void) // This is the definition of foo()
{
    printf("Foo!\n");
}
```

Prototypes for functions that are callable from other source files typically
go in header files, and then those other source files `#include` them.

For functions that aren't used outside the current `.c` file (e.g. little helper
functions that no other file will even need to call), those usually are either
defined at the top of the file before their first call. If that's inconvenient,
a prototype can be placed at the top of the `.c` file, instead.

------------------------------------------------------------------------

<a name="q1600"></a>
### What's the difference between `puts()`, `fprintf()`, and `printf()`?

`puts()` simply outputs a string. It does no formatting of variables. Its only
argument is a single string. Additionally, it prints a newline at the end for
you.

```c
// This prints "Hello, world %d!" and then a newline:
puts("Hello, world %d!");
```

`printf()` does formatted output of variables, and strings as well. It's a
superset of `puts()`, in that way.

```c
int x = 12;

// This prints "Hello, world 12!\n":
printf("Hello, world %d!\n", x);
```

`fprintf()` is just like `printf()`, except it allows you to print to an open file.

```c
FILE *fp = fopen("foo.txt", "w");
int x = 12;

// This writes "Hello, world 12!\n" to the file "foo.txt":
fprintf(fp, "Hello, world %d!\n", x);
```

Incidentally, there's already a file open for you called `stdout` (_standard
output_) which normally prints to the screen. These two lines are equivalent:

```c
printf("Hello, world!\n");
fprintf(stdout, "Hello, world!\n"); // Same thing!
```

There's another already-opened file called `stderr` (_standard error_) that is
typically used to print error messages. Example:

```c
if (argc != 2) {
    fprintf(stderr, "You must specify a command line argument!\n");
    exit(1);
}
```

------------------------------------------------------------------------

<a name="q1700"></a>
### Why does `025 == 21`?

In C, any time you have a plain leading `0` on front of a number, the compiler
thinks your number is _base-8_ or _octal_.

Converting `025` to decimal can be done like so:

`2*8 + 5*1 = 16 + 5 = 21`

Octal is rarely used in practice, and it's common for new C programmers to put
`0` in front of a number in error.

One of the last common places to see octal numbers is in [Unix file
permissions](https://en.wikipedia.org/wiki/File_system_permissions#Numeric_notation).

------------------------------------------------------------------------

<a name="q1800"></a>
### What is the "true dev workflow" in C?

There is none.

Initially, it was in a Unix-like system probably using
[Makefiles](https://en.wikipedia.org/wiki/Makefile) to build the software. This
is the system we use at Lambda.

And modern C development under Unix still follows this pattern, except maybe
using [autotools](https://en.wikipedia.org/wiki/GNU_Build_System) or
[CMake](https://en.wikipedia.org/wiki/CMake).

But dev for specific platforms like Windows probably happens in [Visual
Studio](https://en.wikipedia.org/wiki/Microsoft_Visual_Studio) instead of using
`make` and the rest of it.

------------------------------------------------------------------------

<a name="q1900"></a>
### Does C have garbage collection?

Nope!

When it comes to freeing up memory that is no longer needed by the program,
there are basically two schools of thought:

* Have the programmer manually manage that memory by explicitly allocating and
  freeing it. (C's `malloc()` and `free()` functions.)
* Have the runtime automatically manage all that for you. (Garbage collection,
  automatic reference counting, etc.)

C is too low-level to automatically manage memory usage for you.

One exception is that C automatically allocates and frees _local variables_ just
like other languages you're used to. You don't have to explicitly call `free()`
for locals (and it's an error to do so). You must call free for any and all
pointers to data that you got back from `malloc()` when you're done with them.

Also, when a program exits, all memory associated with it is freed by the OS,
whether locals or `malloc()`d data.

------------------------------------------------------------------------

<a name="q2000"></a>
### Why is C code faster than other languages?

The big thing is _interpreted_ versus _compiled_.

Python and JavaScript are interpreted languages, which means another program
runs your program. It's software running software. So you run python code with
the `python` program and JavaScript code with `node`, for example.

So in that case, we have the CPU running `python`, and the Python running your
Python program. Python is the middleman, and that takes execution time.

C is a compiled language. The compiler takes your C code, and produces machine
code. The CPU runs it directly. No middleman, so it's faster.

But other languages are compiled (like Go, Swift, Rust, C++, and so on). Why is
C faster than them, typically?

It's because C is a no-frills, minimalist language. The code you write in C is
actually quite close to the machine code that gets produced by the compiler, so
it doesn't have to do a lot of things behind your back.

Additionally, people have been working on optimizing the output from C compilers
for over 45 years. That's a big head start over other languages.

------------------------------------------------------------------------

<a name="what-is-segfault"></a><a name="q2100"></a>
### What is a segmentation fault and how do I stop it?

It means you've accessed some memory you weren't supposed to. The OS killed your
process to prevent it from doing so.

The trick is to find the line that's causing the problem. If you get a debugger
installed, this can really help.

In lieu of that, use well-positioned `printf` calls to figure out what the last
thing your program does before it crashes.

The bug almost certainly has to do with pointers or arrays (which are just
pointers behind syntactic sugar).

Maybe you're accessing a `NULL` pointer, or an array out of bounds, or modifying
something you're not allowed to modify.

------------------------------------------------------------------------

<a name="q2200"></a>
### What happens if my program exits but I forgot to `free()` some memory I allocated?

All memory associated with a process is freed when the program exits, even if
you forgot to `free()` it.

It's considered shoddy programming to not `free()` all the things you
`malloc()`d, though. The OS will free it, but it's bad style to rely on that.

------------------------------------------------------------------------

<a name="q2300"></a>
### What's the difference between a `float` and a `double`, or between an `int` and a `long`?

It's all about the range of numbers you want to be able to store.

`double` can hold a more precise number than a `float`.

A `float` might only be precise up to `3.14159`, but a `double` could hold
`3.1416925358979`, for example.

Likewise, an `int` might only be able to hold numbers up to 2 billion or so, but
a `long` could hold much larger numbers.

Use as little as you need. If a `float` or `int` can do the job, use them. If
you need more precision or larger numbers, step up to the next larger type.

------------------------------------------------------------------------

<a name="q2400"></a>
### Can you use `+` to concatenate two strings?

No.

The reason is that strings are represented as `char*` types, and adding two
`char*`s together is not a defined operation in C.

Use the `strcat()` function in `<string.h>` to concatenate one string onto
another.

------------------------------------------------------------------------

<a name="q2500"></a>
### Are variables automatically initialized to zero when I declare them?

No.

Always explicitly initialize your variables, whether they be pointers or regular
types. If you don't, random garbage will be in them when you use them.

> Exception: local variable declared with `static` storage class (this concept
> is out of scope for Lambda) and global variables get initialized to zero
> automatically. But it's still good form to explicitly initialize them.

------------------------------------------------------------------------

<a name="q2600"></a>
### What type should I use to hold numbers bigger than an `int` can hold?

If you don't need negative numbers, try `unsigned int`.

If that's not enough, try `long`.

If that's not big enough, try `long long` (yes, that's a real thing).

If those aren't enough, try `unsigned long long`.

If you just need big numbers, but not a lot of precision, you can use `double` or `long double`.

If you need big numbers _and_ a lot of precision _and_ none of the above are big
enough, check out the [GNU Multiple Precision library](https://gmplib.org/). It
does arbitrary precision arithmetic to as much precision as you have RAM.

------------------------------------------------------------------------

<a name="q2700"></a>
### What VS Code plugins are good for C development?

"C/C++ IntelliSense, debugging, and code browsing" by Microsoft is a good one.

------------------------------------------------------------------------

<a name="q2800"></a>
### What are some additional C resources?

A great C book is _The C Programming Language_ Second Edition, by Kernighan [the
"g" is silent] and Ritchie. It's affectionately referred to simply as _K&R2_.

A less great book that is free online is [Beej's Guide to C
Programming](https://beej.us/guide/bgc/).

A good, comprehensive FAQ is the [comp.lang.c FAQ](http://c-faq.com/).

There's no "one true source" of C info online, unfortunately.

Googling `printf example`, for example, will get you good results.

Googling `man printf` will bring up the `man` page for `printf`.

------------------------------------------------------------------------

<a name="q2900"></a>
### How do I get the debugger working?

The commonly-used debugger is called `gdb` (GNU Debugger).

Lambda's own Brian Ruff got it working on the Mac, and made a
[video](https://youtu.be/BgMOqjdpy5Y) covering it.

[These
instructions](https://www.thegeekstuff.com/2010/03/debug-c-program-using-gdb/)
are reported good for WSL on Windows.

[The CS Wiki
page](https://github.com/LambdaSchool/CS-Wiki/wiki/C-and-Cpp-Debugging-in-VS-Code)
might help, but it's slightly outdated since VS Code is in heavy development.

[This video](https://www.youtube.com/watch?v=aWIs6Kv1MvE) is reported good, as
well.

If you're not seeing program output in the `Output` tab, try adding this to your
`launch.json`:

```json
"externalConsole": true
```

We recommend Googling for `vscode gdb setup macos`, substituting whatever
platform you're on for `macos` and setting the search date range to be recent.

------------------------------------------------------------------------

<a name="q3000"></a>
### How do I print a pointer with `printf`?

Use the `%p` format specifier. This will print the value of the pointer (i.e.
the memory address), not what it's pointing to (i.e. the value stored at that
memory address.)

In practice, pointers are rarely printed except for debugging.

------------------------------------------------------------------------

<a name="q3100"></a>
### Does C have closures?

No, not in the way that you're used to from higher-level languages. What C does have that essentially acts as a poor man's closure is function pointers. These are literally what their name implies: pointers to functions. 

The standard library implementation of the quicksort sorting algorithm provides a good example of this. It's function signature is 
```
void qsort(void *base, size_t nitems, size_t size, int (*compare)(const void *, const void *))
```

The parameter to notice is the `int (*compare)(const void *, const void *)`. This is a function pointer, mainly denoted by the asterisk in front of the function name all wrapped in parentheses and followed by another set of parentheses containing a parameter signature. 

This signature is saying that the `qsort` function, in addition to the other parameters it receives, also receives a pointer to a function that receives two `const void *`s and returns an `int`. 

Function pointers are used to fulfill the same use case as closures. They can be used to pass some dynamic logic into another function. In the case of `qsort`, the function pointer points to a function that specifies how the comparison for the sorting should be done.

------------------------------------------------------------------------

<a name="q3200"></a>
### If I look at an uninitialized variable, will the garbage in it ever be leftover data from another process?

Not on a modern OS. It would be a security risk, so the OS makes sure this never
happens.

------------------------------------------------------------------------

<a name="q3300"></a>
### How many levels of indirection can you have with pointers? `int******`?

It's effectively unlimited. But the more you have, the less readable your code
is.

In real life:

* 99.8% (roughly) of pointer usage is single indirection, like `int*`.
* 1.5% (roughly) is double indirection, like `char**`.
* And the remaining 0.5% is the rest of it.

------------------------------------------------------------------------

<a name="q3400"></a>
### What's the `incompatible integer to pointer conversion` error?

This means you have a type mismatch in your assignment.

One side of the `=` has pointer type, and the other side has integer type.

If you have a pointer in your assignment, both side of the `=` must be the same
pointer type.

Maybe you meant to take the address of the right hand side? Or dereference the
right hand side?

------------------------------------------------------------------------

<a name="q3500"></a>
### Are there any other ways besides `malloc()` to store things on the heap?

Short answer: no.

(We're assuming that by `malloc()` we mean `malloc()`, `calloc()`, and
`realloc()`.)

The longer answer is that you can make a syscall and request more RAM from the
operating system. In practice, this is very rare; people just call `malloc()`.

In Unix, that syscall is `brk()` (or `sbrk()`). The behavior of this call is a bit strange no

------------------------------------------------------------------------

<a name="q3600"></a>
### For string literals like `"Hello"`, are those stored on the stack or heap?

Neither.

Consider it to be stored in such a way that it is perpetually accessible from
the entire program for the entire run and is never freed. So sort of like the
heap.

This code is just fine:

```c
char *hello(void)
{
    char *s = "hello!";

    return s;
}
```

`s` is a local variable that is set to point to the string `"hello!"`, and `s`
is deallocated as soon as the function returns. But the data `s` points to
(namely the `"hello!"`) persists for the entire life of the program and is never
freed.

It's not actually on the heap, though. The C memory map looks like this,
typically:

```
+--------------------+
|       Stack        |
|         |          |
|         v          |
+- - - - - - - - - - +
|                    |
|                    |
|                    |
+- - - - - - - - - - +
|         ^          |
|         |          |
|        Heap        |
+--------------------+
| Uninitialized data |
+--------------------+
|  Initialized data  |
|    (Read-Write)    |
+--------------------+
|  Initialized data  |
|     (Read-Only)    |
+--------------------+
|    Program code    |
+--------------------+
```

Constant strings are found in the read-only initialized data section of memory.

If you try to write to one, your program will likely crash:

```c
char *s = "Hello!";

*s = 'B'; // segfault!
```

------------------------------------------------------------------------

<a name="q3700"></a>
### Is the C stack like the stack data structure?

Yup! It's used by C to allocate space for local variables when you call functions.

When you return from a function, all those local variables are popped off the
stack and thrown away. (Which is why local variables only last as long as the
function!)

------------------------------------------------------------------------

<a name="q3800"></a>
### Is the C heap like a binary heap data structure?

No--it's just a name collision.

Just assume the heap is a big, contiguous chunk of memory. It can be used for
whatever, but in C, it is typically managed by `malloc()` and `free()` so that
we don't have to worry about it.

------------------------------------------------------------------------

<a name="q3900"></a>
### What are `stdin`, `stdout`, and `stderr`?

These are the three files that are automatically opened for a process when it is first created.

|Stream           | File Name |  Device  |
|-----------------|:---------:|:--------:|
| Standard Input  |  `stdin`  | Keyboard |
| Standard Output |  `stdout` |  Screen  |
| Standard Error  |  `stderr` |  Screen  |

`stderr` is typically used specifically for error messages, even though it goes
to the same place as `stdout`. (The idea is that you can redirect all normal
output to one place, and all error output to another place. Or suppress normal
output while allowing error output.)

------------------------------------------------------------------------

<a name="q4000"></a>
### How do I know which header files to `#include` for any particular function?

Check the man page for the function in question. It'll show it in the _Synopsis_
section.

Example for `printf()`:

> **SYNOPSIS**
> ```c
>    #include <stdio.h>
> ```
> ```c
>     int
>     printf(const char * restrict format, ...);
> ```

Note that if you type `man` on the command line for a particular function, you
might a manual page for another command that isn't the C function. In that case,
you have to specify the proper _section_ of the manual for the function.

Try section 3 for library functions, and section 2 for syscalls.

Example looking for `printf()` in section 3:

```shell
man 3 printf
```

And section 2 for the `mkdir()` syscall:

```shell
man 2 mkdir
```

------------------------------------------------------------------------

<a name="q4100"></a>
### When do I have to explicitly cast a type to another type?

Barely ever.

C is pretty good about conversions, and you should be able to build almost
everything without casting.

What if you need constant types?

```c
// Print a double:
// (Floating point constants are double by default.)
printf("%lf\n", 3.14);

// Print a float:
printf("%f\n", 3.14f);

// Print a long double
printf("%Lf\n", 3.14L);

// Print a long integer:
printf("%ld\n", 99L);

// Print a long long integer:
printf("%lld\n", 99LL);

// Produce a floating result of a calculation by making sure at least
// one of the operands is a float:
float sort_of_pi = 22.0f / 7;
double double_pi = 22.0 / 7;
```

What if you need to cast a void pointer?

```c
void foo(void *p)
{
    // convert p to a char*
    char *q = p;

    // Don't need to cast return value from malloc
    int *z = malloc(sizeof(int) * 100);
```

Some exceptions:

```c
void foo(int a)
{
    // Cast an unused variable to type void to suppress compiler warnings:
    (void)a;

    // If the compiler is warning about an unused return value:
    (void)printf("Hello, world!\n");

    // Cast to a char pointer to iterate over bytes of an object:
    // (C99 6.3.2.3 paragraph 7 allows this.)
    float f = 3.14;
    unsigned char *c = (unsigned char *)&f;

    for (unsigned i = 0; i < sizeof f; i++) {
        printf("%02x ", c[i]);
    }
    printf("\n");
```

------------------------------------------------------------------------

<a name="q4200"></a>
### Is `realloc()` the same as calling `malloc()`, copying the data over, then calling `free()` on the original pointer?

Effectively, yes, it's the same. Practically, you should use `realloc()`.

`realloc()` might be more efficient because in some cases it might not have to
copy.

If you grow the space and `realloc()` knows there's extra unused memory right
after the existing space, it will simply tack that addition space onto the end
of the memory region and not bother moving the data.

Also, if you shrink the space, `realloc()` will likely not copy the data. It'll
just truncate it.

------------------------------------------------------------------------

<a name="q4300"></a>
### What happens if I `free()` a `NULL` pointer?

Nothing. It's a [no-op](https://en.wikipedia.org/wiki/NOP_(code)).

Basically, inside the library code for `free()`, there's something that looks
like this:

```c
void free(void *ptr)
{
    if (ptr == NULL) {
        return;
    }
```

According to the [C99
spec](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1124.pdf) section
7.20.3.2p2:

> The `free` function causes the space pointed to by `ptr `to be deallocated,
> that is, made available for further allocation. **If `ptr` is a null pointer,
> no action occurs**. Otherwise, if the argument does not match a pointer
> earlier returned by the `calloc`, `malloc`, or `realloc` function, or if the
> space has been deallocated by a call to `free` or `realloc`, the behavior is
> undefined.

------------------------------------------------------------------------

<a name="q4400"></a>
### What are bits, bytes, kilobytes, megabytes, and all that?

A [_bit_](https://www.youtube.com/watch?v=_fGujzulsas) is a single `1` or `0`.
That's all the numbers it can represent.

A _nibble_ is 4 bits. It can represent numbers from `0b0000` to `0b1111` (binary
numbers), which is equivalen to `0` to `15` in decimal.

A _byte_ is 8 bits. It can represent numbers from `0b00000000` to `0b11111111`,
or `0` to `255` decimal. (Historically, bytes could be other numbers of bits,
but on all modern systems, it's always 8 bits. _Octet_ is another term for a
number that is specifically 8 bits long.)

A _kilobyte_ is 1024 bytes. (1024 is 2<sup>10</sup>.)

A _megabyte_ is 1024 kilobytes (1,048,576 bytes).

A _gigabyte_ is 1024 megabytes (1,073,741,824 bytes).

A _terabyte_ is 1024 gigabytes (1,099,511,627,776 bytes).

A _petabyte_ is 1024 terabytes (1,125,899,906,842,624 bytes).

If you're used to [SI unit
prefixes](https://en.wikipedia.org/wiki/International_System_of_Units#Prefixes),
you might be wondering why in computers _kilo_ means 1024 instead of 1000 like
it normally does. In short, it's for historic reasons. 1024 was close enough, so
computer programmers adopted the SI prefixes, albeit with a slightly different
value.

And that gets confusing. When I say _kilobyte_, do I mean 1000 bytes or 1024 bytes?

In almost every single case, _kilobyte_ means 1024 bytes. (Hard drive and SSD
sizes are sometimes an exception to this rule.)

To remove the ambiguity, you can use a [binary
prefix](https://en.wikipedia.org/wiki/Binary_prefix), where you'd say _kibibyte_
if you specifically meant 1024 bytes.

That said, in conversation, if someone says _kilobyte_, odds are extremely high
they mean 1024 bytes, not 1000 bytes. _kibibyte_ is uncommonly used in
conversation.

------------------------------------------------------------------------

<a name="q4500"></a>
### In C, can we assume an `int` is 32 bits?

No.

You can assume an `int` is _at least_ 16 bits (2 bytes).

There is only one type that has a guaranteed size: `sizeof(char)` will always be
`1` byte. (Same for `unsigned char` and `signed char`.)

Never write code that hardcodes or assumes the size of anything other than
`char`. **Always** use `sizeof` to get the size.

There's a [great Wikipedia article](https://en.wikipedia.org/wiki/C_data_types)
that lists the minimum sizes of the types. If you want your code to be portable
to other compilers and systems, choose a type with a minimum size that works for
the numbers you need to hold.

------------------------------------------------------------------------

<a name="q4600"></a>
### What's the difference between `#include` with double quotes and `#include` with angle brackets?

In general, use double quotes for your own header files, and angle brackets for
built-in system header files like `<stdio.h>`.

When you `#include "foo.h"`, it looks for `foo.h` in the same directory as the
source file doing the including.

You can also use relative paths, and it'll look relative to the including source file:

```c
#include "../bar.h"
#include "somedir/baz.h"
```

When you `#include <frotz.h>`, it looks in the _system include directories_ for
the header file. This is where all the built-in header files are installed. On
Unix machines, this tends to be the `/usr/include` directory, but it depends on
the OS and compiler.

------------------------------------------------------------------------

<a name="q4700"></a>
### Should I declare a pointer to a thing, or just declare the thing?

It depends on if you want a thing or not, or if you just want to point to
another, **already-existing** thing.

If there is not an already-existing thing, then making a pointer doesn't make
sense. There's no existing thing for it to point to.

This does not declare an `int`:

```c
int *p;
```

There's no `int` there. We have an `int` pointer, but it's uninitialized, so it
points to garbage and can't be used.

So the question to ask is, "Do I already have an existing thing that I can point
to? And if so, do I want to point to it?" If the answer to either is "no", then
don't use a pointer.

Example:

```c
int a = 12; // here's an existing thing
```

So the answer to the first part of the question is yes. And do we want a pointer
to it? Sure, why not?

```c
int *p = &a; // and there's a pointer to it
```

------------------------------------------------------------------------

<a name="q4800"></a>
### Is there a difference between `exit()` and `return`?

If you're in the `main()` function, then no.

If you're in any other function, then yes.

`exit()` always exits the running process, no matter where you call it from.

If you're in `main()`, `return` also exits the running process.

If you're in any other function, `return` just returns from that function.

------------------------------------------------------------------------

<a name="q4900"></a>
### Why does `strcmp()` return `0` when strings match? Since `0` means "false" in C, that seems backwards.

`strcmp()` returns the _difference_ between two strings. If the strings are the
same, there is zero difference, so it returns zero.

This gives `strcmp()` a little extra power over just returning a boolean
true/false value.

For example, if you run this:

```c
strcmp("Antelope", "Buffalo");
```

it will return less-than zero because "Antelope" is alphabetically less than
"Buffalo".

So not only can it tell you if the strings are the same, it can tell you their
relative sort order. And that means you can pass it in as the comparator
function to the library built-in `qsort()` function.

------------------------------------------------------------------------

<a name="ub"></a><a name="q5000"></a>
### What is "undefined behavior" in C?

There are a number of things you're allowed to do in C where the compiler is
allowed to produce code that can have any indeterminate effect. It could work,
it could crash, it could sort of work, it could crash sometimes and not others,
it could crash on some machines and not others.

When you write code that does that, we say the code has _undefined behavior_.

[Wikipedia has a number of practical
examples](https://en.wikipedia.org/wiki/Undefined_behavior), and if you look in
the [C99 Language Specification, Annex
J.2](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1124.pdf) you can get a
list of _all_ the things you can do that cause undefined behavior.

At Lambda, the most common things you can do to get UB is using bad pointer references.

* Accessing memory you've already `free()`d.
* Freeing memory more than once.
* Accessing an array off the end of its bounds.
* Dereferencing a pointer that points to garbage.
* Dereferencing a `NULL` pointer.
* Returning a pointer to a local variable and dereferencing that.

GCC with `-Wall -Wextra` should warn on a lot of these. This is why it's
_really_ important to fix all those warnings.

------------------------------------------------------------------------

<a name="q5100"></a>
### When you free a pointer, does it get set to `NULL` automatically?

No.

Furthermore, `free()` can't do that even if it wanted to.

```c
int *p = malloc(100 * sizeof(int));

free(p);
```

When we call `free()`, it gets a _copy_ of the pointer we pass in. (**All**
functions **always** get _copies_ of **all** arguments you pass in.) As such,
`free()` could set its copy of `p` to `NULL`, but that doesn't affect our
original `p`.

`p` remains whatever value was in it until we set it to something else.

```c
int *p = malloc(100 * sizeof(int));

free(p);

p = NULL; // NOW p is NULL
```

(Note that it's [undefined behavior](#ub) to _dereference_ a pointer after
you've `free()`d it. But it's still OK to change that pointer's value.)

------------------------------------------------------------------------

<a name="q5200"></a>
### How do I write preprocessor macros with `#define`?

You've probably already seen simple cases of `#define` like this:

```c
#define antelopes 10

int main(void)
{
    printf("Antelopes: %d\n", antelopes); // prints 10
```

What's actually happening here is the _preprocessor_ runs through the code
before the compiler ever sees it. It manipulates the above code to read:

```c
int main(void)
{
    printf("Antelopes: %d\n", 10); // prints 10
```

and _then_ hands it off to the compiler. The compiler itself knows nothing about
`#define`.

These `#define` _macros_ can also accept parameters that make them behave like
functions in a way.

Example:

```c
#define square(x) x * x // Not quite Right. See below.

int main(void)
{
    printf("9 squared is %d\n", square(9));
```

Then the preprocessor generates this code for the compiler:

```c
int main(void)
{
    printf("9 squared is %d\n", 9 * 9);
```

It just substitutes the parameters in as-is.

Another example:

```c
#define square(x) x * x // Not quite Right. See below.

int main(void)
{
    printf("3 + 2 squared is %d\n", square(3 + 2));
```

Then the preprocessor generates this code for the compiler, merely substituting
in exactly what the dev entered as an argument:

```c
int main(void)
{
    printf("3 + 2 squared is %d\n", 3 + 2 * 3 + 2);
```

Except that prints `11`, when it should print `25` (3 + 2 is 5, and 5 squared is
25)! We have a bug!

Of course, this has to do with the order of operations. We wrote:

```c
3 + 2 * 3 + 2
```

when what we really wanted was:

```c
(3 + 2) * (3 + 2)
```

For this reason, you should **always** put extra parentheses around the macro
body, and around every parameter in the body:

```c
#define square(x) ((x) * (x))
```

And now the expansion of our line will be:

```c
((3 + 2) * (3 + 2))
```

That will work in all expected cases.

------------------------------------------------------------------------

<a name="q5300"></a>
### What is an `undefined symbol` linker error?

This happens when you've called a function, and the _linker_ can't find it in
any of the source files or libraries that you're using.

Do you have a warning about an implicit function declaration from the compiler
before this error? If so, fix that first.

If not, it could be that you haven't specified all the source files needed on
the command line. If you have two sources `one.c` and `two.c`, and one calls
functions that are in the other, then you have to pass both into the compiler:

```
gcc -Wall -Wextra -o myexe one.c two.c
```

Alternately, is there a `Makefile` present? If so, the author of the software
probably intends for you to use that to build the project, rather than trying to
figure out the command line on your own.

Try just running:

```
make
```

and seeing if that works. Make will show you the command lines it's running to
make the build happen so that you don't have to.

The linker is part of the entire compilation system. Basically, the compiler
takes your C source files, makes sure they're syntactically correct, and turns
them into things called _object files_, one per source file. These object files
might refer to functions that they don't contain, like `printf()`, for example.

Then the linker takes all the object files and libraries and puts them together
into a single binary executable that you can run. It makes sure that all the
functions used are present in the files specified.

(Normally this whole process takes place behind the scenes and you don't have to
think about it. Sometimes Makefiles will generate object files that you might
see, e.g. `foo.o`. `.o` is the extension for object files on Unix, or `.obj` in
Windows.)

If the linker can't find a function in any of the object files or libraries, it
pukes out an error. It can't call a function if it can't find it.

In this example, the code calls a function `foobaz()`, but the linker can't find
that in any of the object files:

```
Undefined symbols for architecture x86_64:
  "_foobaz", referenced from:
      _main in foo-133c47.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```

(Ignore the leading underscores on the function names.)

To fix, we need to figure out which file `foobaz()` is defined in, and make sure
to pass that filename to the compiler when we build.

------------------------------------------------------------------------

<a name="q5400"></a>
### How do I make my own header files and what do I put in them?

If you have a `.c` file and you want to be able to use functions, `#define`s, or
globals from that file in another file, you'll need to make a _header file_
(`.h` file) to hold the function prototypes, `#define`s, and references to any
globals.

Example:

```c
// square.c

long square(long x)
{
    return x * x;
}
```

If you want to use `square()` from a different file, you need a way for that
file to know the `square()` function declaration so the compiler can check to
see that you're using it correctly.

For that, we need a corresponding `.h` file:

```c
// square.h

#ifndef SQUARE_H // Prevent multiple #includes
#define SQUARE_H

// Function prototypes
extern long square(long x);

#endif
```

The `#ifndef SQUARE_H` is called the _guard macro_, and is there to prevent the
header file from being included multiple times. (This can be a problem if you
have header files that include other header files in a cycle.) `#ifndef` means
"if not defined". Basically, `SQUARE_H` is acting as a boolean that gets set the
first time through and so prevents the content of the header file from being
included again.

All header files have wrappers like that. The name of the preprocessor variable
is conventionally `FILENAME_H`, but could be anything as long as it's unique in
the project.

The keyword `extern` indicates to the compiler that the function in question is
not defined here; it is defined in another file. In this header file, `extern`
is the default _storage class_ for functions, so it's redundant. But it's really
common to see in any case.

Now that we have a header file, we can `#include` that from somewhere else. Use
double quotes in the `#include` to indicate that the compiler should look in the
current directory for the header file.

```c
#include "square.h"

int main(void)
{
    int x = square(5);
```

When you build, you must specify all `.c` files on the command line:

```
gcc -Wall -Wextra -o main main.c square.c
```

------------------------------------------------------------------------

<a name="q5500"></a>
### How do I make my own Makefile?

**IMPORTANT: Any lines shown _indented_ in any Makefile _must_ begin with a
single TAB character! Spaces will _not_ work. If you use spaces to indent,
you'll likely see a `Missing separator` error when you try to `make`.**

```make
myexecutable: mysource1.c mysource2.c
    gcc -Wall -Wextra -o myexecutable mysource1.c mysource2.c
```

The above Makefile says:

"If `mysource1.c` or `mysource2.c` are _newer_ than `myexecutable`, then run the
following commands in the indented block below this line."

And by "newer", we mean they have a more up-to-date timestamp, i.e. they've been
saved more recently than `myexecutable` has been created.

If any of the sources are newer than the executable, the executable should be
rebuilt to get it up to date. And that's what make does.

We say that `myexecutable` _depends on_ `mysource1.c` and `mysource2.c`. If
either of those dependencies change, `myexecutable` must be rebuilt.

This also works:

```make
myexecutable: mysource1.c mysource2.c
    gcc -Wall -Wextra -o $@ $^
```

`$@` is a make _macro_ that means "substitute whatever is left of the `:` right
here" (in this example, `myexecutable`).

`$^` is a make macro that means "substitute whatever is to the right of the `:`
right here" (in this example, `mysource1.c mysource2.c`).

You can also define constants:

```make
SRCS=mysource1.c mysource2.c
TARGET=myexecutable

$(TARGET): $(SRCS)
    gcc -Wall -Wextra -o $@ $^
```

You can have multiple _recipes_ per Makefile:

```make
target1: source1.c
    gcc -Wall -Wextra -o $@ $^

target2: source2.c
    gcc -Wall -Wextra -o $@ $^
```

If you type `make`, it will build the first _target_ in the file by default. A
target is a file that is generated by running `make`, i.e. a file to the left of
a `:`. You can also make specific targets by specifying them on the command line:

```shell
$ make target1
gcc -Wall -Wextra -o target1 source1.c
$ make target2
gcc -Wall -Wextra -o target2 source2.c
```

If you want all targets to get built by default, you can put a dummy first
target in that depends on the other targets. This target is called `all` by
convention. It typically doesn't run any commands and is only there to set up
the dependency hierarchy with the other recipes.

```make
# Recipe `all` depends on `target1` and `target2`:
all: target1 target2

target1: source1.c
    gcc -Wall -Wextra -o $@ $^

target2: source2.c
    gcc -Wall -Wextra -o $@ $^

.PHONY: all
```

That `.PHONY: all` line is a GNU make extension that indicates that `all` is not
a real file. Normally targets refer to real files, and make will check to see if
that file exists on disk or not before trying to build it. But in this case,
`all` is not a file; it's just recipe we're using to get all targets to build by
default.

* [GNU make documentation](https://www.gnu.org/software/make/manual/make.html)

------------------------------------------------------------------------

<a name="q5600"></a>
### Why are there so many `printf()` variants? How do I know which one to use?

The way to approach it is when you think, "I need something just like
`printf()`, except instead of to the screen, it prints to _x_," then you look in
the man page and see if there's a `printf()` variant that suits your needs.

The first letters let you know what speciality each one has:

* `printf()`: stock, no frills.
* `fprintf()`: "file printf"; print to a specified `FILE*` instead of to `stdout`.
* `sprintf()`: "string printf"; print to a string instead of to `stdout`.
* `snprintf()`: "string printf, with a limited count"; print to a string instead
  of to `stdout`, and also specify the maximum number of characters that
  `snprintf()` is allowed to store in the buffer. This is good to protect
  against buffer overruns, and there's a valid argument that you should _never_
  use `sprintf()`, preferring `snprintf()` instead.
* `vprintf()`: "variadic printf"; anything that starts with a `v` in `printf`
  land has to do with [variadic
  functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html),
  i.e. functions with argument lists of variable lengths. These are out of scope
  at Lambda.
* etc.

------------------------------------------------------------------------

<a name="q5700"></a>
### Why is `main()` always at the bottom of the file?

C has the feature that you have to _declare_ a function before you can use it.
So any functions `main()` needs have to be declared before `main()`, which means
"above" it in the file.

You can also declare functions with _prototypes_ and then put the definition of
`main()` before the definition of the other functions.

It's more common for C devs to put `main()` at the bottom of the file that
contains it, and C devs expect it that way, but it's not wrong or frowned upon
to use prototypes to put it at the top instead.

------------------------------------------------------------------------

<a name="q5800"></a>
### Why does `main()` return `0`? What does the return value mean?

It doesn't _have_ to. The return value from `main()` is the _exit status_ of the
process. This is passed back to the program that first launched your program, so
it can do different things based on the exit status of your program.

Think of it like a way for an exiting program to pass a small piece of
information (an integer) back to the program that spawned it.

`0` by convention means "success". Non-zero means "failure". The idea there is
that there's typically only one way for a program to succeed, but many ways for
it to fail, and you can communicate those different ways with different exit
codes.

Note that you can also use the `exit()` call, passing an exit status code to it
as an argument. Using `return` in `main()` is equivalent to calling `exit()`.

In bash, you can look at the exit status of the previous command by `echo`ing
the `$?` shell variable. In the following example, we use `grep` incorrectly,
and it exits with status `2` to indicate that. Whereas we use `ls` correctly,
and it exits with successful status `0`:

```shell
$ grep
usage: grep [-abcDEFGHhIiJLlmnOoqRSsUVvwxZ] [-A num] [-B num] [-C[num]]
	[-e pattern] [-f file] [--binary-files=value] [--color=when]
	[--context[=num]] [--directories=action] [--label] [--line-buffered]
	[--null] [pattern] [file ...]
$ echo $?
2
$ ls -d .
.
$ echo $?
0
```

At the OS level, `fork()` is used to create a new process, and `wait()` is used
to get the exit status back from that process.

------------------------------------------------------------------------

<a name="q5900"></a>
### Do we have to have a `main()`? Can there be more than one?

Only if you want to have a program that you can run. When you first launch a
program, it looks for a function called `main`.

There can only be one `main()` in a program. (There can only be one of any
function, for that matter.)

It could be that individual files don't have a `main()` in them, but when the
whole project it built, `main()` is brought in from another source file.

Also, there's a thing called a
[library](https://en.wikipedia.org/wiki/Library_(computing)) which is a
collection of functionality that your program makes use of, but doesn't have a
`main()`, itself. Your program has the `main()`, and it just _calls_ routines
that are in the library.

[The C Standard Library](https://en.wikipedia.org/wiki/C_standard_library) is a
library that holds all the standard C functionality (e.g. `printf()`, `sqrt()`,
etc.) but doesn't have a `main()` of its own. Other programs simply use the
library.

------------------------------------------------------------------------

<a name="q6000"></a>
### Can `main()` return `void`? What about `main()` with no parameters?

No. The function signature for `main()` must be one of the following:

```c
int main(void)
int main(int argc, char *argv[])
int main(int argc, char **argv)
```

Note that the second two are equivalent. Use the first form if you don't need to
process command line arguments.

Historically, these were also equivalent, but the second form is now obsolete:

```c
int main(void)  // OK
int main()      // Obsolete
```

------------------------------------------------------------------------

<a name="q6100"></a>
### Do we need a semicolon at the end of every line?

Yes.

Or, more technically, at the end of every statement or expression.

C won't fill them in automatically like JavaScript will.

------------------------------------------------------------------------

<a name="q6200"></a>
### Can a pointer point to more than one thing? What about to arrays and `struct`s?

A pointer is a memory address. A single memory address, a single index number
into your memory array.

As such, it can only point to a single byte in memory.

For single-byte and multi-byte entities, the pointer _always points to the first
first byte of that entity_.

If you have an `int` made up of 4 bytes, a pointer to that `int` points to the
address in memory of the first byte of that `int`.

If you have a `struct`, it points to the first byte of that `struct`.

If you have an array of a zillion `struct`s, it points to the first byte of the
0th `struct` in that array.

------------------------------------------------------------------------

<a name="q6300"></a>
### If variables are stored in memory, where are pointers stored?

Pointers themselves are variables.

Variables are stored in memory.

Therefore pointers are also stored in memory.

Remember that a pointer is just an index into memory. It's just a number; in
fact it's an integer number. We can store integer numbers in memory without a
hassle.

The only difference between a pointer and an integer is that you can dereference
the pointer to see what it's pointing to. You can't dereference an integer. In
memory, they're both just stored as numbers.

------------------------------------------------------------------------
