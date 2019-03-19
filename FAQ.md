# FAQ

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
bytes that are used to represent the number. A `char` is one byte, and an `int`
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

<!--
TODO:

-->

<!-- ============================================================================= -->

<!--
Template:

<p><details><summary><b></b></summary><p>
</p></details></p>
-->
