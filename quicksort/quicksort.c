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

//helper function that creates a pivot point to sort values on either side
int partition(int *arr, int low, int high)
{
    // assign the highest interger in the array to the pivot variable
    int pivot = arr[high];
    // assign the lowest integer to the variable i
    int i = low;

    // for loop
    for (int j = low; j < high; j++)
    {   
        // if the jth index is less than or equal to the pivot int:
        if (arr[j] <= pivot)
        {
            // swap function comes from lib.h
            swap(&arr[j], &arr[i]);
            // iterate i
            i++;
        }
    }
    // use the provided swap function to swap low and high
    swap(&arr[i], &arr[high]);
    //return the new lowest position
    return i;
}

void quicksort(int *arr, int low, int high)
{
    if (low < high) // pretty self explanitory
    {
        // assign a pivot partition for the quicksort to sort on either side
        int index = partition(arr, low, high);
        // recursively sort one side
        quicksort(arr, low, index-1);
        // recursively sort the other side
        quicksort(arr, index+1, high);
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
