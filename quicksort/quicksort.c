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

void quicksort(int *arr, int low, int high)

{

    if (high > low)

    {

        int pivot = arr[low], l = low, r = high + 1;

/* Start with pivot as the value of the first index */

        while (l < r)

        {

/* if the value of l is less than or equal to pivot, increment l -

 as you increment l and decrement r, the point at which they're the same

marks the point in the array where you've performed actions on every element */

            if (arr[l] <= pivot)

            l++;

/* If the value of l is greater than the pivot, decrement r and swap

the element at the address of arr[l] with the element at the address of arr[r] -

This is comparable to creating a greater-than-pivot array because it's moving

elements of the array that are greater than the pivot to the right-hand side */

            else

                swap(&arr[l], &arr[--r]);

        }

/* when you exit the while loop, l and r are both equal -

since you only increase l if the value of arr[l] is less than or equal to the pivot,

swap the address of the pivot with the address of decremented l - this gets the

pivot to where it would be equal to or greater than elements on the left and 

less than or equal to elements on the right.



If at this point, if --l is 0, the first quicksort does not satisfy the if statement

and the first element of the array is considered sorted 



Since l and r were equal before the decrement of l, l is now pointing to another

element in the array than r is - actually, it's pointing to the pivot

- this pivot is not entered into either recursive quicksort call because it's

already guaranteed to be between the elements of the less than pivot sort

and the elements of the greater than pivot sort.



For the second quicksort call, r is passed as the starting index and high as end



If low is greater than high for the second quicksort call, that part of the array

is already sorted */

        swap(&arr[--l], &arr[low]);

        quicksort(arr, low, --l);

        quicksort(arr, r, high);

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