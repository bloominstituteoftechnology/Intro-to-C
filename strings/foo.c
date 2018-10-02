// // Types

// #include <stdio.h>

// int main(void)
// {
//   int a; // int
//   int *p; // pointer to an int, or int-pointer
//   int **q; // pointer to pointer to int

//   a; //int
//   1+a; //int
//   1.2 + a; // float
//   printf("%d\n", a * 4); // int, the return value from printf
//   sqrt(a); // double

//   a / 12; // int
//   a / 12.0; // float
//   a / (float)12; // float
//   (float)a / 12; // float

//   a; // int 
//   &a; // int *

//   p; // int *
//   *p; // int

//   &p; // int **, pointer to a pointer to an int

//   q = &p; // OK pointer to pointer to int on both sides

//   q;      // int **
//   *q;     // int *
//   **q;    // int
//   *(**q);   // error (can't dereference an int)

//   int x;

//   *x;

//   return 0;
// }

// int *a; // a is a pointer to an int
// int *a; // a is a pointer to an int <-- Beej likes this way

// int* c, d; // c is type int*, d is type int

// int *e, f; // e is type int*, f is type int

// *int a; // syntax error
// int a*; // syntax error

// int *a; // int *
// int* a; // int *
// int a; // int

// int *b;

// *b; // valid
// **b; // error, too many dereferences

// int g;

// g*; //syntax error
// g * 2; // mult


// b * 2; // error, no pointer multiply
// *b * 2; // OK, *b is an int

// *b * 2;
// *(b*2); // does it do this? NO
// (*b)*2; // does it do this? YES

// return 0;

// (5 * 3) + (2 * 4)

// int string_to_int(char *s, char **bad) // IRL use strtoul() instead
// {
//   int a = 0;
//   int v;

//   while(*s) { // while *s isn't '\0'
//     a *= 10;
//     // a += *s - 48; // equivalent to the next line:
//     v = *s - '0';

//     *bad = s

//     if (v < 0 || v > 9) {
//       // found a bad character
//       // s points to the bad character
//       // *bad = s;
//       break;
//     }

//     a *= 10;
//     a += v;

//     // a += *s - '0'; // idiomatic
//     // printf("%d\n", *s -48);
//     s++;
//     (*bad)++;
//   }

//   return a;
// }

// int main(void)
// {
//   char *p;

//   printf("%d\n", string_to_int("124x5", &p));

//   printf("%s\n", p); // should print x5
// }

// a = 0; // 0

// a *= 10; // 0
// a += 1; // 1
// a *= 10; // 10
// a += 2; // 12
// a *= 10; // 120
// a += 4; // 124
// a *= 10; // 1240
// a += 5; // 1245

#include <stdio.h>

int string_to_int(char *s, char **bad) // IRL use strtoul() instead
{
    int a = 0;
    int v;

    while(*s) { // while *s isn't '\0'
        v = *s - '0'; // idiomatic

        *bad = s;

        if (v < 0 || v > 9) {
            // found a bad character
            // s points to the bad character
            break;
        }

        a *= 10;
        a += v;

        s++;
        (*bad)++;
    }

    return a;
}

int main(void)
{
    char *p;

    printf("%d\n", string_to_int("124x5", &p));

    printf("%s\n", p); // should print x5
}