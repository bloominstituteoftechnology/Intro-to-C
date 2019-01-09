#include <stdio.h>

int add(int x, int y)
{
    return x + y;
}

int main(void)
{
    int result;

    result = add(12, 3);

    printf("Hello, world! %d\n", result);

    return 0;
}