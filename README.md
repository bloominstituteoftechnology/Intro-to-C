# Introduction to the C Programming Language

Welcome to your first C sprint!

C programming language was developed in 1972 by Dennis Ritchie at bell laboratories of AT&T (American Telephone & Telegraph), located in the U.S.A. Dennis Ritchie is known as the founder of the c language. 
The two main goals of this sprint are as follows. The first goal is to give
students the experience of learning a different programming language. This is
important because it is _very_ rarely the case where you are familiar and
comfortable with all of the technologies/programming languages that you'll be
using on a job as a professional developer. Being able to pick up
languages/technologies you aren't familiar with is a skill that we want to
cultivate in students during their time here at Lambda, which is why we expose
students to both C and Python during their time here.

The second goal is to start peeling away the layers of abstraction that students
are used to from working with JavaScript and Python. Indeed, when you boil it
all down, both JavaScript and Python are implemented in C in the first place! C
supports very few of the abstractions that students are used to, because C has
you working directly with the memory on your machine. Higher level languages
abstract this fact away from you, at the cost of raw performance and control.
Essentially, you're getting exposed to the nitty-gritty seedy underbelly of your
computer's inner workings, and being in such a place for extended periods of
time is not for everybody. 

That being said, we the instructors do believe that every developer needs to get
a taste of C in order to really be able to delve into the inner workings of how
exactly software communicates and interfaces with hardware. That's not really
something JavaScript or Python will expose you to. Additionally, once you get
acclimated to C, the language provides you with unparalleled control over how
your code gets executed on your machine. Some people find the sheer amount of
control that C provides you intoxicating. 

But before any of that happens, you've gotta get your feet wet with C. So without further ado, let's get started!

## What you'll be doing in this sprint

If you haven't gotten your C compiler up and running, please do that first. You'll find instructions on how to do that for your specific platform here: https://github.com/BloomInstituteOfTechnology/CS-Wiki/wiki/Getting-Your-C-Compiler-Installed.

This sprint is structured very much like how your introductory JavaScript sprints are structured. There are independent modules, each with their own set of exercises that you'll be tasked with implementing. There's an associated set of tests for all the exercises in each module, which you'll run against your code to check to see if it behaves and functions correctly. The order in which you should tackle these exercises is this:

  - [ ] fizzbuzz
  - [ ] strings
  - [ ] pointers
  - [ ] malloc
  - [ ] structs

  **Stretch Goal Problems**
  - [ ] queue
  - [ ] quicksort
  - [ ] hangman

Inside a module directory, type `make tests` (just like with the `npm install`
command needing a `package.json` file, the `make` command requires a
`Makefile`), which will do a couple of things as specified by the `Makefile`.
These include compiling your source code inside that module, linking all of the
included header files and libraries, and running the tests for that module. Once
you've gotten all of the tests to pass for that module, move on to the next one.

The code inside the `main` functions are for if you want to compile your file
into an executable for debugging purposes. You don't need to edit any of the
code in the `main` functions. Just type `make` to compile an executable. Then
type `./NAME_OF_EXECUTABLE` (not in caps) to run it, which will execute the code
inside that program's `main` function.

## Troubleshooting

For things that go wrong, check out the [troubleshooting](TROUBLESHOOTING.md) doc.
