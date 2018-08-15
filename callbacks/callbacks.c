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
    /* Given two elements in the array, if the first is greater than the second,
    the two elements are in descending order and need to be swapped, so return 1
    else, return 0 */
    if (a > b)
    {
        return 1;
    }
    return 0;
}

/*
    Implement the callback that will be passed to your bubble_sort function to sort
    the elements in descending (reverse) numerical order.
*/
int reverse_order(int a, int b)
{
    /* Given two elements in the array, if the second is greater than the first,
    the two elements are in ascending order and need to be swapped, so return 1
    else, return 0 */
    if (a < b)
    {
        return 1;
    }
    return 0;
}

/*
    Receives an array of numbers to be sorted, the number of elements in the array,
    and a callback that specifies the order in which the numbers will be sorted.
    Your function should allocate memory to hold the sorted data and return the 
    sorted data. Call the callback as you would any other function. 
*/
int *bubble_sort(int *numbers, int n, compare_cb cmp)
{
    /* Create an int pointer equal to the value of the return of mem_copy,
    which takes a void pointer to a destination array, the pointer of a source array,
    and the number of bytes to be copied and copies the source array into the destination array.
    int *sort is now a pointer to a copy of the numbers array. */

    int *sort = mem_copy(malloc(n * sizeof(int)), numbers, n * sizeof(int));
    /* Create a nested loop and on every loop, invoke the callback,
        passing in the value of sort[j] and the value of sort[j + 1]
        if the return from the callback is greater than 1 (which means the elements are out of order)
        swap the address of sort[j] with the address of sort[j+1] */

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
               if (cmp(sort[j], sort[j + 1]))
               {
                   swap(&sort[j], &sort[j + 1]);
               }
            }
        }
    /* Return the now sorted array */
    return sort;
}


#ifndef TESTING
int main(void)
{
    int arr[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int count = sizeof(arr) / sizeof(arr[0]);
    int *sorted_arr;

    //sorted_arr = bubble_sort(arr, count, sorted_order);
    sorted_arr = bubble_sort(arr, count, reverse_order);

    for (int i = 0 ; i < count ; i++) {
        printf("%d ", sorted_arr[i]);
    }

    printf("\n");

    return 0;
}
#endif
