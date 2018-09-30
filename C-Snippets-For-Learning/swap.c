#include <stdio.h>


void swap(int* a, int* b)
{   // create a pointer called holder that equals the pointer to a
    int holder = *a;
    // swap the value of two pointers
    *a = *b;
    // change pointer b to pointer holder
    *b = holder;
}

int main(void)
{

    int x = 10, y = 20;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);
    return 0;
}

