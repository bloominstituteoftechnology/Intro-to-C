#include <stdio.h>
#include <stdlib.h>
#include "lib.h" 

int partition(int arr[], int pivot, int left, int right)
{
    int pivotValue = arr[pivot];
    int partitionIndex = left;

    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(&arr[i], &arr[partitionIndex++]);
        }
    }

    swap(&arr[right], &arr[partitionIndex]);
    
    return partitionIndex;
}