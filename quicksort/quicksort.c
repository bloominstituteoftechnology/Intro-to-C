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

int descend(int *arr, int pivot, int index) {
    if (index - 1 == pivot){
        swap(arr + pivot, arr + index);
        return index;
    }
    else {
        swap(arr + index, arr + index - 1);
        return descend(arr, pivot, index - 1);
    }
}



void quicksort(int *arr, int low, int high)
{

    //make sure our array length > 1

    //create pivot as first value

    //compare each value from low to high
    //if value is less than pivot, swap with pivot

    //recursively call function from (low, pivot-1) and (pivot+1, high)
    if (high > low) {
        int pivot = low;
        for (int i = low + 1; i <= high; i++) {
            if (arr[i] < arr[pivot]) {
                pivot = descend(arr, pivot, i);
            }
        }

        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

#ifndef TESTING
int main(void)
{
    int arr1[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    {2,1,7,5,0}
    {1,2,7,5,0}
    {0,1,2,7,5}

    int n = sizeof(arr1) / sizeof(arr1[0]);
    quicksort(arr1, 0, n-1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\n");

    return 0;
}
#endif
