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
int partition(int *arr, int low, int high) // create a pivot element which will be basis for the quicksort
{
    int pivot = arr[high];  // initialize pivot element
    int i = low;    // i set to low

    for (int j = low; j < high; j++) { // for loop to iterate over the items in j
        if (arr[j] <= pivot) {    // if the array of j is less than the pivot element
            swap(&arr[j], &arr[i]); // put on the left side of the pivot
            i++; // increment i 
        }
    }
    &swap(arr[i], &arr[high]);  // swap the last element and 2nd to the last element
    return i;                   // return i
}

void quicksort(int *arr, int low, int high) // pass high and low indices
{
    if (low < high) {   // low index is less that the high index 
        int index = partition(arr, low, high); // find index in partition taking in the same array, low, and high indices
        quicksort(arr, low, index -1);   // recursively call quicksort with same array, low index, and index - 1
        quicksort(arr, index + 1, high); // call quicksort with the same array, index + 1, and same high index
        // partitioning the array into 2 halves at the index in the partition function
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
