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
void quicksort(int *arr, int low, int high)
{
    if (low < high) // compares low to high and if low is less than high
    {
        int pivot = low; // sets pivot to low

        for (int i = low; i < high; i++) //  while index is less than high
        {
            if (arr[i] < arr[high]) // compares the array at index is less than array at high
            {
                swap(&arr[pivot], &arr[i]); // swaps the index in the array at th pivot
                pivot++;                    // pivot moves up by one
            }
        }
        swap(&arr[pivot], &arr[high]);   // swaps high at pivot
        quicksort(arr, low, pivot - 1);  // recurses passing array, low and whatever is left of pivot
        quicksort(arr, pivot + 1, high); // recurses to the rigth of pivot
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
