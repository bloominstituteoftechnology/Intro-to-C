#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int result = add(3, 4);

    printf("3 + 4 = %d", result\n);

    return 0;
}

//gcc -Wall -Wextra -o func func.c 
//Note that the -Wall flag turns on all warnings. The -Wextra flag turns on extra warnings.