// Pointer arithmetic
#include <stdio.h>
int main(void)
{
    //! showMemory(start=65520)
    int array[] = {6, 2, -4, 8, 5, 1}; // array[6];
    int *ptr, *ptr2;                   // pointers

    printf("Array contains %d, %d, ... , %d\n", array[0], array[1], array[5]);
    printf("These are stored at %p, %p, ..., %p\n", &array[0], &array[1], &array[5]);
    // array equals &array[0]
    ptr = array;      // address of array[0];
    ptr2 = &array[0]; // same

    *ptr = 10;       // array[0] = 10;
    *(ptr + 1) = 5;  // array[1] = 5;
    *(ptr + 2) = -1; // array[2] = -1;

    *array = 3;        // array[0] = 3;
    *(array + 1) = 10; // array[1] = 10;
    *(array + 2) = 99; // array[2] = 99;

    ptr++;    // address of array[1];
    *ptr = 7; // array[1] = 7;

    ptr += 3; // address of array[1+3];
    *ptr = 8; // array[4] = 8;
    return 0;
}