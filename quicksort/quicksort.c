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

int set_equal_range(int *arr, int position, int head_or_tail) // head_or_tail =>  -1 = head (so head can move to the left) , 1 = tail (so tail can move to the right)
{
    printf("\n\n\nSET EQUAL RANGE\n%d %d \n", position, head_or_tail);
    int move = head_or_tail;
    while (*(arr + position) == *(arr + position + move)) // while current position value equal to immediately next neighbour value
    {
        position = position + move;
    }
    printf("\n\n\nEND SET EQUAL RANGE\n%d %d \n", position, head_or_tail);
    return position;
}

void quicksort(int *arr, int low, int high)
{
    int pivot_index = (low + high) / 2;

    int left = low,
        right = high,

        // This two variables define the range that contains all the possible values taht are equal to the pivot_value
        equal_tail = pivot_index,
        equal_head = pivot_index;

    // set 'starting' head and tail for the values that are equal to the pivot
    equal_head = set_equal_range(arr, equal_head, -1);
    equal_tail = set_equal_range(arr, equal_tail, 1);

    printf("\n\n\nVARIABLES\n%d\n%d %d %d %d \n", pivot_index, left, equal_head, equal_tail, right);

    // while (left < pivot_index || pivot_index > right)
    while (left < equal_head || equal_tail < right)
    {
        printf("\n\n\nVARIABLES\n%d\n%d %d %d %d \n", pivot_index, left, equal_head, equal_tail, right);
        for (int i = 0; i < high + 1; i++)
        {
            printf("%d ", *(arr + i));
        }
        printf("\n");
        for (int i = 0; i < high + 1; i++)
        {
            printf("%d ", i);
        }

        //  CHECK if curren left_value and right_value are equal to pivot_value => set equal_head and equal_tail if needed.
        if (*(arr + left) == *(arr + equal_head) && left != equal_head)
        {
            equal_head--; // move this pointer one position to left
            swap(arr + left, arr + equal_head);
            equal_head = set_equal_range(arr, equal_head, -1); // be sure to put all posible new neighbour equal values into the range
        }
        if (*(arr + right) == *(arr + equal_tail) && right != equal_tail)
        {
            equal_tail++; // move this pointer one position to right
            swap((arr + right), (arr + equal_tail));
            equal_tail = set_equal_range(arr, equal_tail, 1); // be sure to put all posible new neighbour equal values into the range
        }

        // DEFINE left_range_values and right_range_values
        if (*(arr + left) < *(arr + equal_head)) // left_value < pinter_value
        {
            if (*(arr + equal_tail) < *(arr + right)) // pinter_value < right_value
            {
                printf("\n\n< <");
                // Move left and right positions
                if (left < equal_head)
                {
                    left++;
                }
                if (equal_tail < right)
                {
                    right--;
                }
            }
            else if (*(arr + equal_tail) > *(arr + right)) // pinter_value > right_value
            {
                printf("\n\n< >");
                // Move right_value to the left_side
                // In case left = equal_head (the left side has finished looping) -> this actions ensures to make 'room' in the left side to put the right_value.
                swap(arr + equal_head, arr + right);
                equal_head++;

                // at this point the right_value is equial to pivot_value.
                // We have to move that value into the range of equal_values.
                if (equal_tail + 1 == right)
                {
                    // no need to move values.

                    equal_tail++; // so right will be equal to equal_tail
                }
                else
                {
                    swap(arr + equal_tail + 1, arr + right);
                    equal_tail++;
                }

                if (left < equal_head)
                {
                    left++;
                } // move to next value
            }
            else
            {
                printf("\n\n< =");
                if (left < equal_head)
                {
                    left++;
                } // move to next value
            }
        }
        else // left_value > pinter_value
        {
            if (*(arr + equal_tail) < *(arr + right)) // pinter_value < right_value
            {
                printf("\n\n> <");
                // Move left_value to the right_side
                // In case right = equal_tail (the right side has finishied looping) -> this actions ensures to make 'room' in the right side to put the left_value.
                swap(arr + left, arr + equal_tail);
                equal_tail--;

                // At this point the left_value is equal to the pivot_value.
                // We have to move that value into the range of equal_values.
                if (left == equal_head - 1)
                {
                    // no need to move values
                    equal_head--; // so left will be equal to equal_head
                }
                else
                {
                    swap(arr + left, arr + equal_head - 1);
                    equal_head--;
                }

                {
                    right--;
                }
            }
            else if (*(arr + equal_tail) > *(arr + right)) // pointer_value > right_value
            {
                printf("\n\n> >");
                swap((arr + left), (arr + right)); // swap left_value with right_value
                if (left < equal_head)
                {
                    left++;
                }
                if (equal_tail < right)
                {
                    right--;
                }
            }
            else
            {
                printf("\n\n> =");
                if (equal_tail < right)
                {
                    right--;
                }
            }
            //
        }
    }

    printf("\n\n\nEND WHILE VARIABLES\n%d\n%d %d %d %d \n", pivot_index, left, equal_head, equal_tail, right);
    for (int i = 0; i < high + 1; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    for (int i = 0; i < high + 1; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}

#ifndef TESTING
int main(void)
{
    int arr1[] = {100, 55, 95, 98, 10, 18, 90, 95, 95, 11, 47, 67, 89, 42, 49, 79};
    //  arr1[] = {  0,  1, 2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15};
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
