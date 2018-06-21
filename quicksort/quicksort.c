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
// set up partition function for quicksort
int partition (int arr[], int low, int high)
{
 // set variable for the pivot and set the arr index to the high param
    int pivot = arr[high];
    // set up a index variable with the value of low -1
    int i = (low - 1);
 
 // iterate low to high
    for (int j = low; j <= high- 1; j++)
    {
        // if array at index of j is less than or equal to the pivot
        if (arr[j] <= pivot)
        {
            // increment i and swap array at i with array at j
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // swap array at i plus 1 with array at index of high
    swap(&arr[i + 1], &arr[high]);
    // return i plus one
    return (i + 1);
}


void quicksort(int *arr, int low, int high)
{
    // if the int of low is less than the int of high
    if (low < high)
    {
        // set a pi variable, passing in arr, low and high.
        int pi = partition(arr, low, high);
// call quicksort passing in array low and pi minus 1.
        quicksort(arr, low, pi - 1);
// call quick sorty passing in the array pi + 1 and high
        quicksort(arr,pi + 1, high);
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
