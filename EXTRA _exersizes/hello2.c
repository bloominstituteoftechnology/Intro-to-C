#include <stdio.h>

void add10(int *y)
{
   int a  = *y+10;
   *y = a;
}

int main(void)
{
   int x=12;
    add10(&x);//type is int*
    printf("%d\n", x);
    return 0;
}