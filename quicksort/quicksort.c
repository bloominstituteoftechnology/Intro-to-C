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
    int i, j, pivot, temp;

    if(low < high){
        pivot=low;
        i = low;
        j = high;

    while(i<j) {
        while (arr[i] <= arr[pivot] && i < high)
            i++;
        while( arr[j] > arr[pivot])
            j--;
            if(i<j) {
                temp=arr[i];
                arr[i] = arr[j];
                arr[j]=temp;
            }
    }

    temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
    quicksort(arr, low, j - 1);
    quicksort(arr, j + 1, high);
    }

}
// void quicksort(int *arr, int low, int high)
// {
    // int 
    // if( arr[low] > arr[high]) {
    //     swap(&arr[low], &arr[high]);
    //     high--;
    //     quicksort(arr, 0, high);

    // }
    // if(arr[low] > arr[high]){
    //     swap(&arr[low], &arr[high]);
    //     low++;
    //     quicksort(arr, low, high);
    // }
    // else if (arr[low] < arr[high]) {
    //     high--;
    //     quicksort(arr, low, high);
    // }

    // while (arr[low] > arr[high]){
    //     if (arr[low] < arr[high]){
    //         high--;
    //         quicksort(arr, low, high);
    //     }
    //     else {
    //         swap(&arr[low], &arr[high]);
    //         quicksort(arr, low, high);
    //     }
    // }
// }

    // for(int i = high; i >= 0; i--) {
    //     if (arr[low] > arr[i]){
    //         swap(&arr[low], &arr[i]);
    //         quicksort(arr, 0, high);
    //     }
    //     else {
    //         swap(&arr[low], &arr[i]);
    //     }
    // }

    // while(start < end) {
    //     if (start < end) {
    //         high--;
    //         end = arr[high];
    //         printf("%d\n", end);
    //     }
    //     else {
    //         quicksort(arr, 0, n-1 );
    //     }
    // }
    // printf('%d\n', low);
    // printf('%d\n', high);
    // while( arr[low] < arr[high]) {
    // if (arr[low] < arr[high]) {
    //     high--;
    // }
    // else {
    //     // void swap(arr[low], arr[high]);
    //     // void quicksort(arr, low, high);
    //     return 0;
    // }
// }


// #ifndef TESTING
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
// #endif
