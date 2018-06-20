#include <stdio.h>
#include <stdlib.h>
#include "callbacks.h"
#include "lib.h"

/*
    Implement the callback that will be passed to your bubble_sort function to sort 
    the elements in ascending numerical order.
*/
int sorted_order(int a, int b)
{
    return a - b;
}

/*
    Implement the callback that will be passed to your bubble_sort function to sort
    the elements in descending (reverse) numerical order.
*/
int reverse_order(int a, int b)
{
    return b - a;
}

/*
    Receives an array of numbers to be sorted, the number of elements in the array,
    and a callback that specifies the order in which the numbers will be sorted.
    Your function should allocate memory to hold the sorted data and return the 
    sorted data. Call the callback as you would any other function. 

    Use memcopy in lib.h
*/

//compare_cb 'type'; cmp 'function pointer'
int *bubble_sort(int *numbers, int n, compare_cb cmp)
{
    int swappedTrig = 0;
    int *saved = malloc(n * sizeof(int));      // pointer to array after sorting
    mem_copy(saved, numbers, n * sizeof(int)); // copy from numbers to saved.

    for (int i = 0; i < n - 1; i++)
    {
        if (cmp(saved[i], saved[i + 1]) > 0)
        {
            swap(&saved[i], &saved[i + 1]); // swap the addresses
            swappedTrig = 1;
        }
        if (i >= n - 2 && swappedTrig != 0)
        {
            i = -1;
            swappedTrig = 0;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n - 1; j++)
    //     {
    //         if (cmp(target[j], target[j + 1]) > 0)
    //         {
    //             swap(&target[j], &target[j + 1]);
    //         }
    //     }
    // }
    return saved;
}

#ifndef TESTING
int main(void)
{
    int arr[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int count = sizeof(arr) / sizeof(arr[0]);
    int *sorted_arr;

    // sorted_arr = bubble_sort(arr, count, sorted_order);
    sorted_arr = bubble_sort(arr, count, reverse_order);

    for (int i = 0; i < count; i++)
    {
        printf("%d ", sorted_arr[i]);
    }

    printf("\n");

    return 0;
}
#endif
