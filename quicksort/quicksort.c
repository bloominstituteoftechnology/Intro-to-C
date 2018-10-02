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


// void quicksort(int *arr, int low, int high)
// {
//     int low_marker, high_marker, pivot;

//     if(low < high)
//     {
//         pivot=low;
//         low_marker=low;
//         high_marker=high;

//         while(low_marker < high_marker){
//             while(arr[low_marker] <= arr[pivot] && low_marker < high)
//                 low_marker++;
//             while(arr[high_marker] > arr[pivot])
//                 high_marker--;
//             if(low_marker < high_marker)
//             {
//                 swap(arr + low_marker, arr + high_marker);
//             }
//         }

//         swap(arr + pivot, arr + high_marker);
//         quicksort(arr, low, high_marker - 1);
//         quicksort(arr, high_marker + 1, high);
//     }
// }

void quicksort(int *arr, int low, int high)
{
    if(low < high)
    {
        int pivot = low;
        int chopping_block = pivot + 1;

        for(int i = chopping_block; i <= high; i++)
        {
            if(arr[i] < arr[pivot])
            {
                swap(arr + chopping_block, arr + i);
                chopping_block++;
            }
        }
        swap(arr + pivot, arr + (chopping_block - 1));

        quicksort(arr, low, chopping_block - 1);
        quicksort(arr, chopping_block, high);
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
