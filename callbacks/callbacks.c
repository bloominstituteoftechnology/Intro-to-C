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
    return a > b;   // return in ascending order
}

/*
    Implement the callback that will be passed to your bubble_sort function to sort
    the elements in descending (reverse) numerical order.
*/
int reverse_order(int a, int b)
{
    return a < b;   // return reverse order
}

/*
    Receives an array of numbers to be sorted, the number of elements in the array,
    and a callback that specifies the order in which the numbers will be sorted.
    Your function should allocate memory to hold the sorted data and return the 
    sorted data. Call the callback as you would any other function. 
*/
int *bubble_sort(int *numbers, int n, compare_cb cmp)
{
    int *sorted = malloc(n * sizeof(int));  // malloc memory
    mem_copy(sorted, numbers, n * sizeof(int)); // takes the destination pointer, source array/pointer, and the total number of elements/bytes to be copied   

    for (int i = 0; i < n; i++) {   // for loop to iterate over elements in i
        for (int j = 0; j < n - 1; j++) {   // for loop to iterate over elements in j
            if (cmp(sorted[j], sorted[j+1])) {  // next element
                swap(&sorted[j], &sorted[j+1]); // swap them
            }  
        }
    }

    return sorted; 
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
