// Pass arrays to functions

#include <stdio.h>
void printArray(int *, int);
void squareArray(int *, int);
int main(void)
{
    //! showMemory(start=65520)
    int array[] = {6, 2, -4, 8, 5, 1};
    int N = 6;
    printArray(array, 6);
    squareArray(array, 6);
    printArray(array, 6);
    return 0;
}

void squareArray(int *ptr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        ptr[i] = ptr[i] * ptr[i];
        // *(ptr+i) = (*(ptr+i))*(*(ptr+i));
    }
}

void printArray(int *ptr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        // printf("%d ", *(ptr+i));
        printf("%d ", ptr[i]);
    }
    printf("\n");
}