#include <stdio.h>
#include "lib.h"

/*
A regular JS Quicksort algorithm picks a random pivot(item in array) and loops through the remaining elements,
spliting the remaining items into 2 arrays.  Either smaller than pivot or larger than pivot.
Then, it recursively calls quicksort on the 2 arrays until they're all pivots and then they're joined back together.

In C, we are restricted by the fact that C has a set memory space and you can't keep creating 2 new arrays.
Instead, for a C implementation of Quicksort you're passed an array and the lower and higher indices.
You're given the lower and higher indices because getting length is tedious in C (although it can be done)
This method of being given the indices is pretty standard in C programming.
Then instead of making new arrays, you pick a pivot and loop over the other items.
And if the value of the item is lower, you swap the pivot with the item.
Then, recursively Quicksort on the items to the left and right of the pivot. 
*/
void quicksort2(int *arr, int low, int high)
{
    // Exit condition for the quicksort
    if (high > low)
    {
        //We arbitrarily select the leftmost element as the pivot.
        int pivot = low;
        //We want to look at each value in the array after the pivot.
        for (int i = pivot + 1; i <= high; i++)
        {
            //If it's less than the pivot, we need to swap them.
            if (arr[i] < arr[pivot])
            {
                //The implementation on this quicksort swaps the pivot with the item immediately to the right
                //so if item < pivot and item isn't to the right of pivot, move the item to the immediate right of the pivot
                if (i - 1 != pivot)
                {
                    swap(arr + i, arr + pivot + 1);
                }
                //Swap the pivot with the value that is to the right(which is < pivot)
                swap(arr + pivot, arr + pivot + 1);
                //since the values between pivot and item were switched, move pivot pointer up one.
                pivot++;
            }
        }
        //Recurse on the left and right subarrays.
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    // choose arbitrary pivot point
    int pivot = arr[high];
    // int i is used to keep track of array/index of items < pivot
    int i = low;
    // loop over items from index low to index high
    for (int n = low; n < high; n++)
    {
        if (arr[n] <= pivot)
        {
            // if item <= pivot, then move item to index i which is where the < items reside
            swap(&arr[i], &arr[n]);
            // increase i so next item can go there
            i++;
        }
    }
    // swap pivot to in between the two arrays
    swap(&arr[i], &arr[high]);
    return i;
}
// from solution lecture
void quicksort(int *arr, int low, int high)
{
    if (low < high) {
        int index = partition(arr, low, high);
        quicksort(arr, low, index - 1);
        quicksort(arr, index + 1, high);
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
