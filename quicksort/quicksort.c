#include <stdio.h>
#include <stdlib.h>
#include "lib.h" 

/*
    Implement the Quicksort algorithm. You'll likely want to re-use the
    `swap` function you implemented in the pointers module (which is
    already being included for you in this file).
*/
void quicksort(int arr[], int low, int high)
{
	int a, b, pivot;
	if (low < high) {
		pivot = low;
		a = low;
		b = high;
		while (a < b) {
			while (arr[a] <= arr[pivot] && a < high) {
				a++;
			}
			while (arr[b] > arr[pivot]) {
				b--;
			}
			if (a < b) {
				swap(&(arr[a]), &(arr[b]));
			}
		}		
		swap(&(arr[pivot]), &(arr[b]));
		quicksort(arr, low, (b - 1));
		quicksort(arr, (b + 1), high);
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
