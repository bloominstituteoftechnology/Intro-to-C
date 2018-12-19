// 0x8 = 0
// 1x8 = 8
// ...
// 10x8 = 80
#include <stdio.h>
int main(void)
{
    int result = 0;
    int num = 0;
    int i;
    for (i = 0; i < 11; i++)
    {
        printf("%dx8 = %d\n", num, result);
        num = num + 1;
        result = num * 8;
    }
    return 0;
}