// Types
#if 0
             a  q  p
addresses: 0123456789 <- bucket numbers
             ^  ^  ^
             99 8  2    **q
#endif
int main(void)
{
    int a = 99;            // int
    int *p;                // pointer to an int, or int-pointer
    int **q;               // pointer to pointer to int
    a;                     // int
    1 + a;                 // int
    1.2 + a;               // float
    printf("%d\n", a * 4); // int, the return value from printf
    sqrt(a);               // double
    a;                     // int
    &a;                    // int *
    p = &a;
    q = &p;
    p;      // int *
    *p;     // int
    &p;     // int **, pointer to a pointer to an int
    q = &p; // OK pointer to pointer to int on both sides, int **
    q;      // int **
    *q;     // int *
    **q;    // int
    ***q;   // error!
    return 0;

    // *****
    int *a;    // a is a pointer to an int
    int *a;    // a is a pointer to an int <-- Beej likes this way
    int *c, d; // c is type int*, d is type int
    int *e, f; // e is type int*, f is type int
    *int a;    // syntax error
    int a *;   // syntax error
    int *a;    // int *
    int *a;    // int *
    int a;     // int
    int *b;
    *b;  // valid
    **b; // error, too many dereferences
    int g;
    g *;   // syntax error
    g * 2; // mult
    b * 2; // error, no pointer multiply
    // *****
}

// (sleep 60; echo 'hi!') &
// kill()