#include <stdio.h>
#include "lib.h" 

/*
    Implement the Quicksort algorithm. You'll likely want to re-use the
    `swap` function you implemented in the pointers module (which is
    already being included for you in this file).
*/
void quicksort(int arr[], int low, int high)
{
    if (low < high){ 
        int pivot = low;
        // If integer is LESS than the pivot, it is swapped with pivot.

        // If you want to manually print:
        // printf("value stored at arr pointer: %x\n", *(arr));
        // printf("value stored at arr pointer: %x\n", *(arr + 15));

        // arr = [ 4, 10, 11, 18, 42, 43, 47, 49, 55, 67, 79, 89, 90, 95, 98, 100 ]​​​​​
        // BUT in HEX
        // so arr = [4, a , b, 12, 2a ... 4f]

        // printf("Address of arr pointer: %x\n", arr);
        // printf("value stored at arr pointer: %x\n", *(arr + 4));
        // printf("LOW: %i\n", low); // `low` is the address for the first integer => 0
        // printf("PIVOT: %i\n", pivot);
        // printf("HIGH: %i\n", high); // `high` is the address for the last integer => 15

        // https://beginnersbook.com/2015/02/quicksort-program-in-c/


        for (int i = low; i < high; i++) {
            if (arr[i] < arr[high]) {
                swap(&arr[pivot], &arr[i]);
                // int temp = arr[pivot];
                // arr[pivot] = arr[i];
                // arr[i] = temp;
                pivot++;
            }
        }
        // Once the above is completed, then you assign `high` as the new pivot
        swap(&arr[pivot], &arr[high]);
        // Run quicksort on section of array from low to pivot -1
        quicksort(arr, low, pivot - 1);
        // Run quicksort on section of array from pivot + 1 to high
        quicksort(arr, pivot + 1, high);
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
