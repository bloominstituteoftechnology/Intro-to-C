# FAQ

<p><details><summary><b><tt>runtests.sh: 4: Syntax error: word unexpected (expecting "do")</tt></b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b><tt>runtests.sh: 3: 56059 Segmentation fault: 11  $VALGRIND</tt></b></summary><p>

This means you got a segfault in your program. See [What is a segmentation fault
and how do I stop it?](#what-is-segfault)

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>Mac: <tt>malformed object</tt> error when running <tt>make tests</tt></b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>Can I accidentally destroy my computer running C code?</b></summary><p>

Nope! Not with a modern OS.

If you're running MS-DOS, then sure, you can do all kinds of things.
I once accidentally blew away all my BIOS settings with a program I
wrote and my computer wouldn't boot.

But Windows, Linux, macOS, BSD, or any other mainstream OS from this century all
offer memory and resource protection that prevents you from changing memory
you're not supposed to, or wiping out a disk you're not supposed to, etc.

The worst you'll see is a `Segmentation fault` message which means your program
tried to do something bad and the OS killed it.

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>Is a <tt>struct</tt> comparable to something in Python or JS? Is it like a class?</b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>Can you have default parameters in the structs?</b></summary><p>

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
</p></details></p>

<p><details><summary><b>Why does unsigned char type accept a number when it's clearly referring to a character?</b></summary><p>

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

</p></details></p>

<p><details><summary><b>When I pass an array as an argument to a function, when do I use pointer notation and when do I use array notation ?</b></summary><p>

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
</p></details></p>

<p><details><summary><b>Why do functions tend to return pointers to structs, and not just copies of the struct?</b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>Why do we subtract '0' from a char to convert it from ASCII to a numeric value?</b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>When do I need a pointer to a pointer?</b></summary><p>

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
</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>Do other languages use pointers?</b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>What's the difference between "<tt>int *x</tt>" and "<tt>int* x</tt>"?</b></summary><p>

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
</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>What does the "implicit declaration of function" warning mean?</b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>What's the difference between <tt>puts()</tt>, <tt>fprintf()</tt>, and <tt>printf()</tt>?</b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>Why does <tt>025 == 21</tt>?</b></summary><p>

In C, any time you have a plain leading `0` on front of a number, the compiler
thinks your number is _base-8_ or _octal_.

Converting `025` to decimal can be done like so:

`2*8 + 5*1 = 16 + 5 = 21`

Octal is rarely used in practice, and it's common for new C programmers to put
`0` in front of a number in error.

One of the last common places to see octal numbers is in [Unix file
permissions](https://en.wikipedia.org/wiki/File_system_permissions#Numeric_notation).

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>What is the "true dev workflow" in C?</b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>Does C have garbage collection?</b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>Why is C code faster than other languages?</b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<a name="what-is-segfault"></a>
<p><details><summary><b>What is a segmentation fault and how do I stop it?</b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>What happens if my program exits but I forgot to <tt>free()</tt> some memory I allocated?</b></summary><p>

All memory associated with a process is freed when the program exits, even if
you forgot to `free()` it.

It's considered shoddy programming to not `free()` all the things you
`malloc()`d, though. The OS will free it, but it's bad style to rely on that.

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>What's the difference between a <tt>float</tt> and a <tt>double</tt>, or between an <tt>int</tt> and a <tt>long</tt>?</b></summary><p>

It's all about the range of numbers you want to be able to store.

`double` can hold a more precise number than a `float`.

A `float` might only be precise up to `3.14159`, but a `double` could hold
`3.1416925358979`, for example.

Likewise, an `int` might only be able to hold numbers up to 2 billion or so, but
a `long` could hold much larger numbers.

Use as little as you need. If a `float` or `int` can do the job, use them. If
you need more precision or larger numbers, step up to the next larger type.

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>Can you use <tt>+</tt> to concatenate two strings?</b></summary><p>

No.

The reason is that strings are represented as `char*` types, and adding two
`char*`s together is not a defined operation in C.

Use the `strcat()` function in `<string.h>` to concatenate one string onto
another.

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>Are variables automatically initialized to zero when I declare them?</b></summary><p>

No.

Always explicitly initialize your variables, whether they be pointers or regular
types. If you don't, random garbage will be in them when you use them.

> Exception: local variable declared with `static` storage class (this concept
> is out of scope for Lambda) and global variables get initialized to zero
> automatically. But it's still good form to explicitly initialize them.

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>What type should I use to hold numbers bigger than an <tt>int</tt> can hold?</b></summary><p>

If you don't need negative numbers, try `unsigned int`.

If that's not enough, try `long`.

If that's not big enough, try `long long` (yes, that's a real thing).

If those aren't enough, try `unsigned long long`.

If you just need big numbers, but not a lot of precision, you can use `double` or `long double`.

If you need big numbers _and_ a lot of precision _and_ none of the above are big
enough, check out the [GNU Multiple Precision library](https://gmplib.org/). It
does arbitrary precision arithmetic to as much precision as you have RAM.

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>What VS Code plugins are good for C development?</b></summary><p>

"C/C++ IntelliSense, debugging, and code browsing" by Microsoft is a good one.

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>What are some additional C resources?</b></summary><p>

A great C book is _The C Programming Language_ Second Edition, by Kernighan [the
"g" is silent] and Ritchie. It's affectionately referred to simply as _K&R2_.

A less great book that is free online is [Beej's Guide to C
Programming](https://beej.us/guide/bgc/).

A good, comprehensive FAQ is the [comp.lang.c FAQ](http://c-faq.com/).

There's no "one true source" of C info online, unfortunately.

Googling `printf example`, for example, will get you good results.

Googling `man printf` will bring up the `man` page for `printf`.

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>How do I get the debugger working?</b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>How do I print a pointer with <tt>printf</tt>?</b></summary><p>

Use the `%p` format specifier. This will print the value of the pointer (i.e.
the memory address), not what it's pointing to (i.e. the value stored at that
memory address.)

In practice, pointers are rarely printed except for debugging.

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>Does C have closures?</b></summary><p>

No.

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>If I look at an uninitialized variable, will the garbage in it ever be leftover data from another process?</b></summary><p>

Not on a modern OS. It would be a security risk, so the OS makes sure this never
happens.

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>How many levels of indirection can you have with pointers? <tt>int******</tt>?</b></summary><p>

It's effectively unlimited. But the more you have, the less readable your code
is.

In real life:

* 99.8% (roughly) of pointer usage is single indirection, like `int*`.
* 1.5% (roughly) is double indirection, like `char**`.
* And the remaining 0.5% is the rest of it.

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>What's the <tt>incompatible integer to pointer conversion</tt> error?</b></summary><p>

This means you have a type mismatch in your assignment.

One side of the `=` has pointer type, and the other side has integer type.

If you have a pointer in your assignment, both side of the `=` must be the same
pointer type.

Maybe you meant to take the address of the right hand side? Or dereference the
right hand side?

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>Are there any other ways besides <tt>malloc()</tt> to store things on the heap?</b></summary><p>

Short answer: no.

(We're assuming that by `malloc()` we mean `malloc()`, `calloc()`, and
`realloc()`.)

The longer answer is that you can make a syscall and request more RAM from the
operating system. In practice, this is very rare; people just call `malloc()`.

In Unix, that syscall is `brk()` (or `sbrk()`). The behavior of this call is a bit strange no

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>For string literals like <tt>"Hello"</tt>, are those stored on the stack or heap?</b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>Is the C stack like the stack data structure?</b></summary><p>

Yup! It's used by C to allocate space for local variables when you call functions.

When you return from a function, all those local variables are popped off the
stack and thrown away. (Which is why local variables only last as long as the
function!)

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>Is the C heap like a binary heap data structure?</b></summary><p>

No--it's just a name collision.

Just assume the heap is a big, contiguous chunk of memory. It can be used for
whatever, but in C, it is typically managed by `malloc()` and `free()` so that
we don't have to worry about it.

</p></details></p>

<!-- ===================================================================== -->

<p><details><summary><b>What are <tt>stdin</tt>, <tt>stdout</tt>, and <tt>stderr</tt>?</b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>How do I know which header files to <tt>#include</tt> for any particular function?</b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>When do I have to explicitly cast a type to another type?</b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>Is <tt>realloc()</tt> the same as calling <tt>malloc()</tt>, copying the data over, then calling <tt>free()</tt> on the original pointer?</b></summary><p>

Effectively, yes, it's the same. Practically, you should use `realloc()`.

`realloc()` might be more efficient because in some cases it might not have to
copy.

If you grow the space and `realloc()` knows there's extra unused memory right
after the existing space, it will simply tack that addition space onto the end
of the memory region and not bother moving the data.

Also, if you shrink the space, `realloc()` will likely not copy the data. It'll
just truncate it.

</p></details></p>


<!-- ============================================================================= -->

<p><details><summary><b>What happens if I <tt>free()</tt> a <tt>NULL</tt> pointer?</b></summary><p>

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

</p></details></p>
<!-- ============================================================================= -->

<p><details><summary><b>What are bits, bytes, kilobytes, megabytes, and all that?</b></summary><p>

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

</p></details></p>

<!-- ============================================================================= -->

<p><details><summary><b>In C, can we assume an <tt>int</tt> is 32 bits?</b></summary><p>

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

</p></details></p>

<!--
TODO:

#include rules, current directory, etc.
should I declare a pointer to a thing, or just declare a thing?
exit() vs return from main
Why does strcmp() return 0 when strings match? Since 0 means false in C, that seems backwards.
What is "undefined behavior" in C?


-->

<!-- ============================================================================= -->

<!--
Template:

<p><details><summary><b></b></summary><p>
</p></details></p>

-->
