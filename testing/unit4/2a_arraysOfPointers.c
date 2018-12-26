Define and work with arrays of pointers and use multiple ways for dereferencing

#include <stdio.h>
int main(void)
{
    //! showMemory(cursors=[a, arrays[0], b, arrays[1], c, arrays[2]], start=65520)
    short a[3] = {234, 655, 843};
    short b[2] = {12, 62};
    // short c[4] = {3456, 3467, 23, 276}; // array of arrays(pointers)
    short *arrays[3] = {a, b, c};
    *arrays[0] = 5;       // a[0] = 5
    arrays[0][0] = 0;     // a[0] = 0
    *(arrays[0] + 1) = 6; // a[1] = 6
    arrays[0][1] = 0;     // a[1] = 0
    *(arrays[0] + 2) = 7;
    arrays[0][2] = 0;
    *arrays[1] = 3;       // b[0] = 3
    arrays[1][0] = 0;     // b[0] = 0
    *(arrays[1] + 1) = 4; // b[1] = 4
    arrays[1][1] = 0;     // b[1] = 0
    *(arrays[2] + 3) = 2;
    arrays[2][3] = 3;
    return 0;
}