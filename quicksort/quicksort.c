#include <stdio.h>
#include "lib.h" 

/*
    Implement the Quicksort algorithm. You'll likely want to re-use the
    `swap` function you implemented in the pointers module (which is
    already being included for you in this file).
*/
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int smaller = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            smaller++;
            swap(&arr[smaller], &arr[j]);
        }
    }

    swap(&arr[smaller + 1], &arr[high]);
    printf("printArr\n");
    printArray(arr, high + 1);
    return (smaller + 1);
}

void quicksort(int arr[], int low, int high)
{   
    if (high == 0) {
        printf("%d\n", *arr);
    }
   
    if (low < high) {
        int pi = partition(arr, low, high);
        printf("pi %d\n", pi);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
   
}

#ifndef TESTING
int main(void)
{
    int arr1[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(arr1) / sizeof(arr1[0]); // 16
    quicksort(arr1, 0, n-1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\n");

    return 0;
}

// void quicksort(int arr[], int low, int high)
// {   
    
//     int pivot; 
//     int i; 
//     int j;
//     int temp;
//     // int arr1[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
//     // 79, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 100
//     if (low < high) {
//         pivot = low;
//         i=low;
//         j=high;
//         while (i < j) {
//             while (arr[i] <= arr[pivot] && i < high) {
//                 i++;
//             }
//             while (arr[j] > arr[pivot]) {
//                 j--;
//             }
//             if (i < j) {
//                 temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//         temp = arr[pivot];
//         arr[pivot] = arr[j];
//         arr[j] = temp;
//         quicksort(arr, low, j - 1);
//         quicksort(arr, j + 1, high);
//     }
//     // printf("arr: %d\n", low);
// }
#endif
