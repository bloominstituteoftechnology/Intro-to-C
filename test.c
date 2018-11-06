#include <stdio.h>
#include <stdlib.h>


void swap(int* a, int* b) {
    printf("%d and %d", *a,*b);
}

int main(void)
{
    int a = 6;
    int b = 5;
    swap(&a, &b);

    return 0;
}