#include <stdio.h>
#include <stdlib.h>
#include "lib.h" 

/*
    Implement the Quicksort algorithm. You'll likely want to re-use the
    `swap` function you implemented in the pointers module (which is
    already being included for you in this file).
*/

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//This works
void quicksort(int arr[], int low, int high)
{
    if(low < high)
    {   
        int pi= low;
        int pivot = arr[high];
        for(int i = low; i < high ; i++){
            if(arr[i] < pivot){
                swap(&arr[pi], &arr[i]);
                pi++;
            }
        }
        swap(&arr[pi], &arr[high]);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
//This doesn't work. Goes in infinite loop
void quicksort(int arr[], int low, int high)
{
    if(low < high)
    {   
        int* lowpointer = &arr[low];
        printf("The value of current lowpointer %d\n",*lowpointer);
        printf("The address of current lowpointer is %d\n",lowpointer);
        int pivot = arr[high];
        for(int i = low; i < high ; i++){
            if(arr[i] < pivot){
                swap(lowpointer, &arr[i]);
                lowpointer++;
            }
        }
        swap(lowpointer, &arr[high]);
        printf("The address of left arr is %d\n",lowpointer-&arr[low]-1);
        printf("The address of right arr is %d\n",lowpointer-&arr[low]+1);
        quicksort(arr,low,lowpointer-&arr[low]-1);
        quicksort(arr,lowpointer-&arr[low]+1,high);
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