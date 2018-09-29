#include <stdio.h>


void swap(int* a, int* b)
{
    printf(a, b);
}

int main(void)
{

    int one = 1;
    int two = 2;
    int *pointer_to_one = one;
    int *pointer_to_two = two;
    swap(pointer_to_one, pointer_to_two);
    // printf("Before swap: one: %d, two: %d.", pointer_to_one, pointer_to_two);
    // printf("After swap: one: %d, two: %d.", pointer_to_one, pointer_to_two); 
    return 0;
}

