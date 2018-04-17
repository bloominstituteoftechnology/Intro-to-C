#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/*
    Implement the Quicksort algorithm. You'll likely want to re-use the
    `swap` function you implemented in the pointers module (which is
    already being included for you in this file).
*/

int split(int arr[], int low, int high) 
{
    // int pivot = (*low + *high) / 2;
    // int i = *low;
    // int j = *high;
    // while (i <= j) {
    //     while (arr[i] < pivot) {
    //         i++;
    //     }
    //     while (arr[j] > pivot) {
    //         j--;
    //     }
    //     if (i <= j) {
    //         swap(low, high);
    //         i++;
    //         j--;
    //     }
    // }
    // return i;
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j += 1) {
        if (arr[j] <= pivot) {
            i += 1;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high)
{
    // int index;
    // if (string_length(arr) > 1) {
    //     index = split(arr, &low, &high);
    //     if (low < index - 1) {
    //         quicksort(arr, low, high);
    //     }
    //     if (index < high) {
    //         quicksort(arr, index, high);
    //     }
    // }
    if (low < high) {
        int s = split(arr, low, high);
        quicksort(arr, low, s - 1);
        quicksort(arr, s + 1, high);
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
