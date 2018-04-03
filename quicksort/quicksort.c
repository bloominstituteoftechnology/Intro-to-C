#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/*
    Implement the Quicksort algorithm. You'll likely want to re-use the
    `swap` function you implemented in the pointers module (which is
    already being included for you in this file).
*/

int partition(int subArr[], int subLow, int subHigh)
{
  int pivot = subArr[subHigh];
  int i = (subLow - 1);
  for (int j = subLow; j <= subHigh - 1; j++)
  {
    if (subArr[j] <= pivot)
    {
      i++;
      swap(&subArr[i], &subArr[j]);
    }
  }
  swap(&subArr[i + 1], &subArr[subHigh]);
  return (i + 1);
}

void quicksort(int arr[], int low, int high)
{
  if (low < high)
  {
    int partArr = partition(arr, low, high);
    quicksort(arr, low, partArr - 1);
    quicksort(arr, partArr + 1, high);
  }
}

#ifndef TESTING
int main(void)
{
  int arr1[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
  int n = sizeof(arr1) / sizeof(arr1[0]);
  quicksort(arr1, 0, n - 1);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr1[i]);
  }

  printf("\n");

  return 0;
}
#endif
