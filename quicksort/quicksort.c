#include <stdio.h>
#include "lib.h" // swap function

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
int partition(int *arr, int low, int high)
{
  int pivot = low;

  for (int i=low+1; i < high+1; i++)
  {
    if (arr[low] >= arr[i])
    {
      pivot++;
      swap(&arr[i], &arr[pivot]);
    }
  }
  swap(&arr[pivot], &arr[low]);
  return pivot;
}

void quicksort(int *arr, int low, int high) // O(nlogn)
{
  if (low < high)
  {
    int pivot = partition(arr, low, high); // finds the pivot
    quicksort(arr, low, pivot-1); // checks the left half
    quicksort(arr, pivot+1, high); // checks the right half
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
