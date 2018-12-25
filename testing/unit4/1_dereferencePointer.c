#include <stdio.h>
int main(void)
{
    //! showMemory(start=65520)
    int i = 42;
    int *iAdr;
    double a = 3.14;
    double *aAdr = &a;
    char c = 'p';
    char *cAdr = &c;
    iAdr = &i; // alternatively int * iAdr = &i;
    printf("Address of i is %p and i = %d.\n", iAdr, *iAdr);
    printf("Address of a is %p and a = %lf.\n", aAdr, *aAdr);
    printf("Address of c is %p and c = %c.\n", cAdr, *cAdr);
    *iAdr = 50;
    printf("Address of i is %p and i = %d.\n", iAdr, i);
    *aAdr = 2.1718;
    printf("Address of a is %p and a = %lf.\n", aAdr, a);
    *cAdr = 'B';
    printf("Address of c is %p and c = %c.\n", cAdr, c);

    return (0);
}
// Address of i is fffc and i = 42.
// Address of a is fff0 and a = 3.140000.
// Address of c is ffeb and c = p.
// Address of i is fffc and i = 50.
// Address of a is fff0 and a = 2.171800.
// Address of c is ffeb and c = B.
