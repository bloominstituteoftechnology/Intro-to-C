#include <stdio.h>
#include "lib.h"

/*
    Implement the Quicksort algorithm. You'll likely want to re-use the
    `swap` function you implemented in the pointers module (which is
    already being included for you in this file).

    The `low` and `high` parameters indicate the lowest and highest indices
    of the array that is getting passed in. This is necessary because the 
    function is being passed a pointer to the array, not the contents of the
    array. We can't easily figure out the length of the array through the 
    pointer, so the function receives the highest and lowest indices as
    parameters to circumvent this issue.
    
    Do not just use the `qsort` function from the standard library.
*/

int set_equal_range(int *arr, int position, int head_or_tail) // head_or_tail =>  -1 = head , 1 = tail
{
    int move = head_or_tail;
    while (*(arr + position) == *(arr + position + move)) // while current position value equal to immediately next neighbour value
    {
        position = position + move;
    }
    return position;
}

void quicksort(int *arr, int low, int high)
{
    int pivot_index = (low + high) / 2;

    int left = low,
        right = high,
        equal_tail = pivot_index,
        equal_head = pivot_index;

    // set 'starting' head and tail for the values that are equal to the pivot
    equal_head = set_equal_range(arr, equal_head, -1);
    equal_tail = set_equal_range(arr, equal_tail, 1);

    while (left != equal_head || equal_tail != right)
    {
        if (*(arr + left) == *(arr + equal_head))
        {
            equal_head--; // move this pointer one position to left
            swap(left, equal_head);
            equal_head = set_equal_range(arr, equal_head, -1); // be sure to put all posible new neighbour equal values into the range
        }
        if (*(arr + right) == *(arr + equal_tail))
        {
            equal_tail++; // move this pointer one position to right
            swap(*(arr + right), *(arr + equal_tail));
            equal_tail = set_equal_range(arr, equal_tail, 1); // be sure to put all posible new neighbour equal values into the range
        }
    }
}

#ifndef TESTING
int main(void)
{
    int arr1[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    quicksort(arr1, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }

    printf("\n");

    return 0;
}
#endif
