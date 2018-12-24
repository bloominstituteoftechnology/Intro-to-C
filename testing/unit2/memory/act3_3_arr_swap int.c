// The main function first reads 6 integers from the input, and assigns them to the array. The main function then calls reverseArray, passing the array as an argument.
// The main function then prints the reversed array.
#include <stdio.h>

//Write your function prototype here
void reverseArray(int *);
int main(void)
{
    //! showMemory(start=65520)
    int array[6], user_i;
    for (int i = 0; i < 6; i++)
    {
        scanf("%d ", &user_i);
        array[i] = user_i;
    }
    reverseArray(array);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", array[i]);
    }
}
void reverseArray(int *ptr)
{
    int temp = *ptr;
    *ptr = *(ptr + 5);
    *(ptr + 5) = temp;
    int temp1 = *(ptr + 1);
    *(ptr + 1) = *(ptr + 4);
    *(ptr + 4) = temp1;
    int temp2 = *(ptr + 2);
    *(ptr + 2) = *(ptr + 3);
    *(ptr + 3) = temp2;
}

// solution
#include <stdio.h>

void reverseArray(int *arr);

int main(void)
{
    int arr[6];
    int i;

    for (i = 0; i < 6; i++)
    {
        scanf("%d", &arr[i]);
    }

    reverseArray(arr);

    for (i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void reverseArray(int *arr)
{
    int swap;

    swap = arr[5];
    arr[5] = arr[0];
    arr[0] = swap;

    swap = arr[4];
    arr[4] = arr[1];
    arr[1] = swap;

    swap = arr[3];
    arr[3] = arr[2];
    arr[2] = swap;
}