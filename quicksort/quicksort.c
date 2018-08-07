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

    Reference: https://www.tutorialspoint.com/data_structures_algorithms/quick_sort_algorithm.htm
*/

int findPartitionIndex(int *arr, int left, int right, int pivot)
{
    int leftPointer = left - 1;
    int rightPointer = right;

    while (1) {
        while (arr[++leftPointer] < pivot) {
            continue;
        }

        while (rightPointer > 0 && arr[--rightPointer] > pivot) {
            continue;
        }

        if (leftPointer >= rightPointer) {
            break;
        }
        else {
            swap(&arr[leftPointer], &arr[rightPointer]);
        }
    }
    swap(&arr[leftPointer], &arr[right]);
    return leftPointer;
}

void quicksort(int *arr, int low, int high)
{
    // printf("Pivot: %i\n", arr[high]);
    if (high - low <= 0) {
        return;
    }
    else {
        int pivot = arr[high];
        int index = findPartitionIndex(arr, low, high, pivot);
        // printf("index: %i\n", index);
        // swap(&arr[index], &arr[high]);
        quicksort(arr, low, index - 1);
        quicksort(arr, index + 1, high);
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
