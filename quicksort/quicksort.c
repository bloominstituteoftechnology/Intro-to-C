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
int partition(int *arr, int low, int high) {
  int i = low + 1;    // index of the smaller element
  int piv = arr[low];   // make the first element as pivot element

  for (int j = low + 1; j <= high; j++) {
    /* rearrange the array by putting elements which are less than pivot
       on the left side and which are greater on the right side */
    if (arr[j] < piv) {
      swap(&arr[i], &arr[j]);
      i++;
    }
  }
  swap(&arr[low], &arr[i - 1]);   // put the pivot element in its proper place
  return i - 1;   // return the position of the pivot
}

void quicksort(int *arr, int low, int high)
{
  if (low < high) {
    // stores the position of pivot element
    int piv_pos = partition(arr, low, high);
    quicksort(arr, low, piv_pos - 1);   // sort the left side of pivot
    quicksort(arr, piv_pos + 1, high);   // // sort the right side of pivot
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
