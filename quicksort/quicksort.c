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
    int pivot, i, j, temp;
    if(low < high) {
        pivot = high; // select a pivot element...doesn't matter if it's low or high
        i = low;
        j = high;
        while(i < j) {
        // increment i till you get a number greater than the pivot element
            while(arr[i] <= arr[pivot] && i <= high)
                i++;
        // decrement j till you get a number less than the pivot element
            while(arr[j] > arr[pivot] && j >= low)
                j--;
        // if i < j swap the elements in locations i and j
        if(i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // when i >= j it means the j-th position is the correct position
    // of the pivot element, hence swap the pivot element with the
    // element in the j-th position
    temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;
    // Repeat quicksort for the two sub-arrays, one to the left of j
    // and one to the right of j
    quicksort(arr, low, j-1);
    quicksort(arr, j+1, high);
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
