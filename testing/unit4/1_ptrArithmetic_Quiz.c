#include <stdio.h>
int main(void)
{
    //! showMemory(start=65520)
    int numbers[] = {4, -1, 8, 3, 0, -11};
    printf("%d\n", *numbers);       // array[0] = 4
    printf("%p\n", numbers);        // address of array[0]
    int atr = *numbers + 4;         // atr = array[0] + 4 = 4 + 4 = 8
    printf("%d\n", atr);            // 8
    printf("%d\n", *(numbers + 4)); // value of array[4] = 0
    int *ptr;                       // init
    ptr = numbers + 2;              // address of array[2]
    ptr++;                          // adress of array[3]
    printf("%d\n", *ptr);           // value of array[3] = 3
    printf("%d\n", numbers[10]);    // ?
    return 0;
}