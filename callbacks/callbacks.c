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

return a > b;
}

/*
    Implement the callback that will be passed to your bubble_sort function to sort
    the elements in descending (reverse) numerical order.
*/
int reverse_order(int a, int b)
{
return a < b;
}

/*
    Receives an array of numbers to be sorted, the number of elements in the array,
    and a callback that specifies the order in which the numbers will be sorted.
    Your function should allocate memory to hold the sorted data and return the 
    sorted data. Call the callback as you would any other function. 
*/
int *bubble_sort(int *numbers, int n, compare_cb cmp)
{
    // set up array variable setting it to  malloc with n times the size of int(4)
int *array = malloc(n * sizeof(int));
// call mem copy passing in the array along with numbers and n times 4
mem_copy(array,numbers,n* sizeof(int));
// iterate over while i is less than n
for(int i=0; i<n; i++)
{
    // iterate over while j is less than n
    for(int j = 0; j<n -1 ; j++)
    {
        // if you compare the array at j and the array at j plus 1
        // also if cmp is not false or greater than 0
        if(cmp(array[j], array[j +1] )>0)
        {
        // swap array at j with array at j + 1
            swap(&array[j],&array[j +1]);
        }
    }
}
// return the updated array.
return array;

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
