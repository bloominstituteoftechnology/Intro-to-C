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

    Step 1 − Choose the highest index value has pivot
    Step 2 − Take two variables to point left and right of the list excluding pivot
    Step 3 − left points to the low index
    Step 4 − right points to the high
    Step 5 − while value at left is less than pivot move right
    Step 6 − while value at right is greater than pivot move left
    Step 7 − if both step 5 and step 6 does not match swap left and right
    Step 8 − if left ≥ right, the point where they met is new pivot

    https://www.tutorialspoint.com/data_structures_algorithms/quick_sort_algorithm.htm
*/

int partitionIndex(int *arr, int left, int right, int pivot)
{
    int leftPointer = left;
    int rightPointer = right - 1;

    while (1) {
        while (arr[leftPointer] < pivot) {
            leftPointer++;
        }

        while (rightPointer > 0 && arr[rightPointer] > pivot) {
            rightPointer--;
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
    if (high - low <= 0) {
        return;
    }
    else {
        int pivot = arr[high];
        int index = partitionIndex(arr, low, high, pivot);
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
