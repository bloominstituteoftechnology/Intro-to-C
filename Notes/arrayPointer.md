#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char a[128];
    char *b = malloc(128);

    a[0] = 'B';
    a[1] = 'e';
    a[2] = 'e';
    a[3] = 'j';
    a[4] = '\0';

    b[0] = 'A'; // Same as pointer notation, below
    b[1] = 'd';
    b[2] = 'a';
    b[3] = 'm';
    b[4] = '\0';

    *(b+0) = 'A'; // Same as array notation, above
    *(b+1) = 'd';
    *(b+2) = 'a';
    *(b+3) = 'm';
    *(b+4) = '\0';

    printf("%s\n", a);
    printf("%s\n", b);

    return 0;
}