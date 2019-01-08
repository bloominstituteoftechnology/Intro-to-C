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
int partition(int *arr, int low, int high){
    int pivot = low;
    int* ptr = arr;
    for (int i=low+1; i<=high; i++){
        // for (int i=0; i < (high-low); i++) {
        //     printf("%d ", arr[i]);
        // }
        // printf("\n");         
        if (arr[i] <= arr[low]){
            pivot++;
            swap(ptr+i, ptr+pivot);   
        }
    }
    swap(ptr+pivot, ptr+low);
    return pivot;
}

void quicksort(int *arr, int low, int high){
    // for (int i=0; i < (high-low); i++) {
    //     printf("%d ", arr[i]);
    // }
    if (low < high){
        int pivot = partition(arr, low, high);
        // printf("pivot: %d", pivot);
        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1, high);
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
