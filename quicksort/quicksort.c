#include <stdio.h>
#include <stdlib.h>
#include "lib.h" 

/*
    Implement the Quicksort algorithm. You'll likely want to re-use the
    `swap` function you implemented in the pointers module (which is
    already being included for you in this file).
*/
int partition(int arr[], int low, int high, int pivot) {
    while(low <= high) {
        while(arr[low] < pivot) {
            low++;
        }

        while(arr[high] > pivot) {
            high--;
        }

        if(low <= high) {
            swap(&low, &high);
            low++;
            high--;
        }
    }
    return low;
}

void quicksort(int arr[], int low, int high)
{
    if(arr[low] < arr[high]){
        return;
    }
    
    int pivot = arr[(low + high) / 2];
   

    int index = partition(arr, low, high, pivot);
    quicksort(arr, low, index - 1);
    quicksort(arr, index, high);

    return;
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
