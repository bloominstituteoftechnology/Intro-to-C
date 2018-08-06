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
    //If the array is not of size > 1, it is already trivially sorted.
    if (high > low) {
        //We arbitrarily select the leftmost element as the pivot.
        int pivot = low;
        //We want to look at each value in the array after the pivot.
        for (int i = pivot + 1; i <= high; i++) {
            //If it's less than the pivot, we need to swap them.
            if (arr[i] < arr[pivot]) {
                //If it's not already adjacent to the pivot...
                if (i - 1 != pivot){
                    //Swap with the value that is.
                    swap(arr + i, arr + pivot + 1);
                }
                //Swap the pivot and our lesser value, which
                //is now adjacent to the pivot on its right.
                swap(arr + pivot, arr + pivot + 1);
                //The pivot moved one position to the right.
                pivot++;
            }
        }
        //Recurse on the left and right subarrays.
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}



#ifndef TESTING
int main(void)
{
    int arr1[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    quicksort(arr1, 0, n-1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\n");

    return 0;
}
#endif
